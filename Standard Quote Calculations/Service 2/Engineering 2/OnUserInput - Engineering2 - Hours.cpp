row.Total=IFNULL(row.Rate,0.00) * IFNULL(row.Hours,0.00);
//Vat
vat = Global_Settings[KEY == "DEFAULT_VAT"].VALUE.toDecimal();
vat = IFNULL(vat,0.00) / 100;
//
if(row.Discount_Type.contains("Percentage"))
{
	discount = IFNULL(row.Discount_Amount,0) / 100;
	totalDiscount = IFNULL(row.Total,0) * discount;
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
// Total Set Up
totalSetUpNet = 0;
totalSetUpDiscount = 0;
if(input.Set_Up_Fees_2.count() > 0)
{
	for each  setUpData in input.Set_Up_Fees_2
	{
		totalSetUpNet = totalSetUpNet + IFNULL(setUpData.sf_Total1,0);
		totalSetUpDiscount = totalSetUpDiscount + IFNULL(setUpData.Total_Discount,0);
	}
}
//Total Equipment
totalEquipmentNet = 0;
totalEqupmentDiscount = 0;
if(input.Service_Equipment_2.count() > 0)
{
	for each  equipmentData in input.Service_Equipment_2
	{
		totalEquipmentNet = totalEquipmentNet + equipmentData.Total;
		totalEqupmentDiscount = totalEqupmentDiscount + equipmentData.Total_Discount;
	}
}
//Total Engineering
totalEngineeringNet = 0;
totalEngineeringDiscount = 0;
if(input.Service_Engineering_2.count() > 0)
{
	for each  engineeringData in input.Service_Engineering_2
	{
		totalEngineeringNet = totalEngineeringNet + IFNULL(engineeringData.Total,0);
		totalEngineeringDiscount = totalEngineeringDiscount + IFNULL(engineeringData.Total_Discount,0);
	}
}
//Carriage
input.Total_Carriage_2 = IFNULL(input.Carriage_2,0);
// OVERALL TOTAL
totalNet = totalSetUpNet + totalEquipmentNet + totalEngineeringNet;
totalDiscount = totalSetUpDiscount + totalEqupmentDiscount + totalEngineeringDiscount;
totalVat = totalNet * vat;
totalNonRecurring = totalNet - totalDiscount;
input.Non_recurring_charges_Net_2 = totalNet;
input.Non_recurring_charges_Discount_2 = totalDiscount;
input.Non_recurring_Vat_2 = totalVat;
input.Non_recurring_charges_Total_2 = totalNonRecurring + totalVat + IFNULL(input.Carriage_2,0);
