// TAX
vat = Global_Settings[KEY == "DEFAULT_VAT"].VALUE.toDecimal();
vat = IFNULL(vat,0.00) / 100;
if(input.sc1 == true)
{
	totalSetUpItem = IFNULL(row.Fee,0) * IFNULL(row.sf_Quantity1,0);
	row.sf_Total1 = totalSetUpItem;
	if(row.Discount_Type.contains("Percentage"))
	{
		discount = IFNULL(row.Discount_Amount,0) / 100;
		row.Total_Discount=discount * totalSetUpItem;
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
	totalSetUpItem = IFNULL(row.Fee,0);
	row.sf_Total1 = totalSetUpItem;
	if(row.Discount_Type.contains("Percentage"))
	{
		discount = IFNULL(row.Discount_Amount,0) / 100;
		row.Total_Discount=discount * totalSetUpItem;
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
// Total Set Up
totalSetUpNet = 0;
totalSetUpDiscount = 0;
if(input.Set_Up_Fees_2.count() > 0)
{
	for each setUpData in input.Set_Up_Fees_2
	{
		totalSetUpNet += IFNULL(setUpData.sf_Total1,0);
		totalSetUpDiscount += IFNULL(setUpData.Total_Discount,0);
	}
}
//Total Equipment
totalEquipmentNet = 0;
totalEqupmentDiscount = 0;
if(input.Service_Equipment_2.count() > 0)
{
	for each equipmentData in input.Service_Equipment_2
	{
		totalEquipmentNet += equipmentData.Total;
		totalEqupmentDiscount += equipmentData.Total_Discount;
	}
}
//Total Engineering
totalEngineeringNet = 0;
totalEngineeringDiscount = 0;
if(input.Service_Engineering_2.count() > 0)
{
	for each engineeringData in input.Service_Engineering_2
	{
		totalEngineeringNet += IFNULL(engineeringData.Total,0);
		totalEngineeringDiscount += IFNULL(engineeringData.Total_Discount,0);
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