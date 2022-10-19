//Vat
vat = Global_Settings[KEY == "DEFAULT_VAT"].VALUE.toDecimal();
vat = IFNULL(vat,0.00) / 100;
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
//Total Set Up
totalSetUpNet = 0;
totalSetUpDiscount = 0;
if(input.Set_Up_Fees_3.count() > 0)
{
	for each  setUpData in input.Set_Up_Fees_3
	{
		totalSetUpNet = totalSetUpNet + IFNULL(setUpData.sf_Total2,0);
		totalSetUpDiscount = totalSetUpDiscount + IFNULL(setUpData.Total_Discount,0);
	}
}
//Total Equipment
totalEquipmentNet = 0;
totalEqupmentDiscount = 0;
if(input.Service_Equipment_3.count() > 0)
{
	for each  equipmentData in input.Service_Equipment_3
	{
		totalEquipmentNet = totalEquipmentNet + IFNULL(equipmentData.Total,0);
		totalEqupmentDiscount = totalEqupmentDiscount + IFNULL(equipmentData.Total_Discount,0);
	}
}
//Total Engineering
totalEngineeringNet = 0;
totalEngineeringDiscount = 0;
if(input.Service_Engineering_3.count() > 0)
{
	for each  engineeringData in input.Service_Engineering_3
	{
		totalEngineeringNet = totalEngineeringNet + IFNULL(engineeringData.Total,0);
		totalEngineeringDiscount = totalEngineeringDiscount + IFNULL(engineeringData.Total_Discount,0);
	}
}
//Carriage
input.Total_Carriage_3 = IFNULL(input.Carriage_3,0);
//Overall Total
totalNet = totalSetUpNet + totalEquipmentNet + totalEngineeringNet;
totalDiscount = totalSetUpDiscount + totalEqupmentDiscount + totalEngineeringDiscount;
totalVat = totalNet * vat;
totalNonRecurring = totalNet - totalDiscount;
input.Non_recurring_charges_Net_3 = totalNet;
input.Non_recurring_charges_Discount_3 = totalDiscount;
input.non_recurring_Vat_3 = totalVat;
input.Non_recurring_charges_Total_3 = totalNonRecurring + totalVat + IFNULL(input.Carriage_3,0);
