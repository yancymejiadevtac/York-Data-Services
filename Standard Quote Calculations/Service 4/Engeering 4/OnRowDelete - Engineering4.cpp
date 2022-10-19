//GLOBAL VARIABLES
vat = Global_Settings[KEY == "DEFAULT_VAT"].VALUE.toDecimal();
vat = IFNULL(vat,0.00) / 100;
//
var_deleted_value = IFNULL(row.Total,0.00);
var_deleted_discount = IFNULL(row.Total_Discount,0);
//Total Set Up
totalSetUpNet = 0;
totalSetUpDiscount = 0;
if(input.Set_Up_Fees_4.count() > 0)
{
	for each  setUpData in input.Set_Up_Fees_4
	{
		totalSetUpNet = totalSetUpNet + IFNULL(setUpData.sf_Total3,0);
		totalSetUpDiscount = totalSetUpDiscount + IFNULL(setUpData.Total_Discount,0);
	}
}
//Total Equipment
totalEquipmentNet = 0;
totalEqupmentDiscount = 0;
if(input.Service_Equipment_4.count() > 0)
{
	for each  equipmentData in input.Service_Equipment_4
	{
		totalEquipmentNet = totalEquipmentNet + IFNULL(equipmentData.Total,0);
		totalEqupmentDiscount = totalEqupmentDiscount + IFNULL(equipmentData.Total_Discount,0);
	}
}
//Total Engineering
totalEngineeringNet = 0;
totalEngineeringDiscount = 0;
if(input.Service_Engineering_4.count() > 0)
{
	for each  engineeringData in input.Service_Engineering_4
	{
		totalEngineeringNet = totalEngineeringNet + IFNULL(engineeringData.Total,0);
		totalEngineeringDiscount = totalEngineeringDiscount + IFNULL(engineeringData.Total_Discount,0);
	}
}
//Carriage
input.Total_Carriage_4 = IFNULL(input.Carriage_4,0);
// OVERALL TOTAL
totalNet = totalSetUpNet + totalEquipmentNet + totalEngineeringNet - var_deleted_value;
totalDiscount = totalSetUpDiscount + totalEqupmentDiscount + totalEngineeringDiscount - var_deleted_discount;
totalVat = totalNet * vat;
totalNonRecurring = totalNet - totalDiscount;
input.Non_recurring_charges_Net_4 = totalNet;
input.Non_recurring_charges_Discount_4 = totalDiscount;
input.non_recurring_Vat_4 = totalVat;
input.Non_recurring_charges_Total_4 = totalNonRecurring + totalVat + IFNULL(input.Carriage_4,0);
