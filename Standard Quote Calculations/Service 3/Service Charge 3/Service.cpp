//VAT
vat = Global_Settings[KEY == "DEFAULT_VAT"].VALUE.toDecimal();
vat = IFNULL(vat,0.00) / 100;
//Auto-populate fields
row.Monthly_Service_Fee=IFNULL(row.Service.Monthly_Service_Fee,0.00);
if(input.sc2 == true)
{
	totalSChargeItem = IFNULL(row.sc_Quantity2,0) * IFNULL(row.Monthly_Service_Fee,0);
	row.sc_Total2=totalSChargeItem;
	if(row.Discount_Type.contains("Percentage"))
	{
		discount = IFNULL(row.Discount_Amount,0) / 100;
		row.Total_Discount=discount * totalSChargeItem;
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
else if(input.sc2 == false)
{
	totalSChargeItem = IFNULL(row.Monthly_Service_Fee,0);
	row.sc_Total2=totalSChargeItem;
	if(row.Discount_Type.contains("Percentage"))
	{
		discount = IFNULL(row.Discount_Amount,0) / 100;
		row.Total_Discount=discount * totalSChargeItem;
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
if(input.Service_Charges_3.count() > 0)
{
	totalNet = 0;
	totalDiscount = 0;
	for each  serviceData in input.Service_Charges_3
	{
		totalNet = totalNet + IFNULL(serviceData.sc_Total2,0);
		totalDiscount = totalDiscount + IFNULL(serviceData.Total_Discount,0);
	}
	totalVat = totalNet * vat;
	totalRecurring = totalNet - totalDiscount;
	input.Recurring_service_charges_Net_3 = totalNet;
	input.Recurring_service_charges_Discount_3 = totalDiscount;
	input.recurring_Vat_3 = totalVat;
	input.Recurring_service_charges_Total_3 = totalRecurring + totalVat;
}
