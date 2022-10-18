//VAT
vat = Global_Settings[KEY == "DEFAULT_VAT"].VALUE.toDecimal();
vat = IFNULL(vat,0.00) / 100;
if(input.sc1 == true)
{
	totalSChargeLineItem = IFNULL(row.Monthly_Service_Fee,0) * IFNULL(row.sc_Quantity1,0);
	row.sc_Total1=totalSChargeLineItem;
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
else if(input.sc1 == false)
{
	totalSChargeLineItem = IFNULL(row.Monthly_Service_Fee,0);
	row.sc_Total1=totalSChargeLineItem;
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
//Total
if(input.Service_Charges_2.count() > 0)
{
	totalNet = 0;
	totalDiscount = 0;
	for each  serviceData in input.Service_Charges_2
	{
		totalNet = totalNet + IFNULL(serviceData.sc_Total1,0);
		totalDiscount = totalDiscount + IFNULL(serviceData.Total_Discount,0);
	}
	totalVat = totalNet * vat;
	totalRecurring = totalNet - totalDiscount;
	input.Recurring_service_charges_Net_2 = totalNet;
	input.Recurring_service_charges_Discount_2 = totalDiscount;
	input.recurring_Vat_2 = totalVat;
	input.Recurring_service_charges_Total_2 = totalRecurring + totalVat;
}
