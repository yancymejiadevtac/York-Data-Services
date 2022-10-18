row.Total=IFNULL(row.Price,0.00) * IFNULL(row.Quantity,0);
//Vat
vat = Global_Settings[KEY == "DEFAULT_VAT"].VALUE.toDecimal();
vat = IFNULL(vat,0.00) / 100;
if(row.Discount_Type.contains("Percentage"))
{
	discount = IFNULL(row.Discount_Amount,0) / 100;
	totalDiscount = IFNULL(row.Total,0) * discount;
	row.Total_Discount = totalDiscount;
}
else if(row.Discount_Type.contains("Fixed"))
{
	row.Total_Discount = IFNULL(row.Discount_Amount,0);
}
else
{
	row.Total_Discount = 0;
}
//
// Total Set Up
totalSetUpNet = 0;
totalSetUpDiscount = 0;
if(input.Set_Up_Fees.count() > 0)
{	
	for each setUpData in input.Set_Up_Fees
	{
		totalSetUpNet += IFNULL(setUpData.sf_Total0,0);
		totalSetUpDiscount += IFNULL(setUpData.Total_Discount,0);
	}
}
//Total Equipment
totalEquipmentNet = 0;
totalEqupmentDiscount = 0;
if(input.Service_Equipment.count() > 0)
{
	for each equipmentData in input.Service_Equipment
	{
		totalEquipmentNet += IFNULL(equipmentData.Total,0);
		totalEqupmentDiscount += IFNULL(equipmentData.Total_Discount,0);
	}
}
//Total Engineering
totalEngineeringNet = 0;
totalEngineeringDiscount = 0;
if(input.Service_Engineering.count() > 0)
{
	for each engineeringData in input.Service_Engineering
	{
		totalEngineeringNet += IFNULL(engineeringData.Total,0);
		totalEngineeringDiscount += IFNULL(engineeringData.Total_Discount,0);
	}
}
//Carriage
input.Total_Carriage1 = IFNULL(input.Carriage,0);
// OVERALL TOTAL
totalNet = totalSetUpNet + totalEquipmentNet + totalEngineeringNet;
totalDiscount = totalSetUpDiscount + totalEqupmentDiscount + totalEngineeringDiscount;
totalVat = totalNet * vat;
totalNonRecurring = totalNet - totalDiscount;
input.Non_recurring_charges_Net = totalNet;
input.Non_recurring_Discount = totalDiscount;
input.Non_recurring_Vat_1 = totalVat;
input.Non_recurring_charges_Total = totalNonRecurring + totalVat + IFNULL(input.Carriage,0);
