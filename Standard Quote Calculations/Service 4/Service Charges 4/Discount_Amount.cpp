//VAT
vat = Global_Settings[KEY == "DEFAULT_VAT"].VALUE.toDecimal();
vat = IFNULL(vat,0.00) / 100;
if(row.Discount_Type.contains("Percentage"))
{
	discount = IFNULL(row.Discount_Amount,0) / 100;
	totalDiscount = IFNULL(row.sc_Total3,0) * discount;
	row.Total_Discount = totalDiscount;
}
else if(row.Discount_Type.contains("Fixed"))
{
	row.Total_Discount=IFNULL(row.Discount_Amount,0);
}
else
{
	row.Total_Discount=0;
}
//Total
if(input.Service_Charges_4.count() > 0)
{
	totalNet = 0;
	totalDiscount = 0;
	for each  serviceData in input.Service_Charges_4
	{
		totalNet += IFNULL(serviceData.sc_Total3,0);
		totalDiscount = totalDiscount + IFNULL(serviceData.Total_Discount,0);
	}
	totalVat = totalNet * vat;
	totalRecurring = totalNet - totalDiscount;
	input.Recurring_service_charges_Net_4 =totalNet;
	input.Recurring_service_charges_Discount_4 = totalDiscount;
	input.recurring_Vat_4 = totalVat;
	input.Recurring_service_charges_Total_4 = totalRecurring + totalVat;
}