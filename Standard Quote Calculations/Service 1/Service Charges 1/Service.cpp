//VAT
vat = Global_Settings[KEY == "DEFAULT_VAT"].VALUE.toDecimal();
vat = IFNULL(vat,0.00) / 100;
//Auto Populate Fields
row.Supplier_Name=IFNULL(row.Service.Supplier_Name,"");
row.Monthly_Service_Fee=IFNULL(row.Service.Monthly_Service_Fee,0.00);
if(input.sc0 == true)
{
	totalSChargeLineItem = IFNULL(row.Monthly_Service_Fee,0.00) * IFNULL(row.sc_Quantity0,0.00);
	row.sc_Total0=totalSChargeLineItem;
	if(row.Discount_Type.contains("Percentage"))
	{
		discount = IFNULL(row.Discount_Amount,0) / 100;
		row.Total_Discount=discount * totalSChargeLineItem;
	}
	else if(row.Discount_Type.contains("Fixed"))
	{
		row.Total_Discount=IFNULL(row.Discount_Amount,0);
	}
	else
	{
		row.Total_Discount=0;
	}
}
else if(input.sc0 == false)
{
	totalSChargeLineItem = IFNULL(row.Monthly_Service_Fee,0.00);
	row.sc_Total0=totalSChargeLineItem;
	if(row.Discount_Type.contains("Percentage"))
	{
		discount = IFNULL(row.Discount_Amount,0) / 100;
		row.Total_Discount=discount * totalSChargeLineItem;
	}
	else if(row.Discount_Type.contains("Fixed"))
	{
		row.Total_Discount=IFNULL(row.Discount_Amount,0);
	}
	else
	{
		row.Total_Discount=0;
	}
}
if(input.Service_Charges.count() > 0)
{
	totalNet = 0;
	totalDiscount = 0;
	for each  serviceData in input.Service_Charges
	{
		totalNet = totalNet + IFNULL(serviceData.sc_Total0,0);
		totalDiscount = totalDiscount + IFNULL(serviceData.Total_Discount,0);
	}
	totalVat = totalNet * vat;
	totalRecurring = totalNet - totalDiscount;
	input.Recurring_service_charge_Net = totalNet;
	input.Recurring_Disount = totalDiscount;
	input.recurring_Vat_1 = totalVat;
	input.Recurring_service_charges_Total = totalRecurring + totalVat;
}
