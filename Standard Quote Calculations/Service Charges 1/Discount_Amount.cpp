//VAT
vat = Global_Settings[KEY == "DEFAULT_VAT"].VALUE.toDecimal();
vat = IFNULL(vat,0.00) / 100;
//Computations
if(row.Discount_Type.contains("Percentage"))
{
	discount = IFNULL(row.Discount_Amount,0) / 100;
	totalDiscount = IFNULL(row.sc_Total0,0) * discount;
	row.Total_Discount=totalDiscount;
}
else if(row.Discount_Type.contains("Fixed"))
{
	row.Total_Discount=IFNULL(row.Discount_Amount,0);
}
else
{
	row.Total_Discount=0;
}
// Recurring Service Charges
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
