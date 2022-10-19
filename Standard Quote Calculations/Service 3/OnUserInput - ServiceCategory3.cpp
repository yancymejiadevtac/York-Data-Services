if(Service_Category_3.Category_Name.contains("Co-Location") || Service_Category_3.Category_Name.contains("IP") || Service_Category_3.Category_Name.contains("Managed Service") || Service_Category_3.Category_Name.contains("VoIP"))
{
	input.sc2 = true;
	show Service_Charges_3.sc_Quantity2;
	// 	show Service_Charges_3.sc_Total2;
	show Set_Up_Fees_3.sf_Quantity2;
	// 	show Set_Up_Fees_3.sf_Total2;
}
else
{
	input.sc2 = false;
	hide Service_Charges_3.sc_Quantity2;
	// 	hide Service_Charges_3.sc_Total2;
	hide Set_Up_Fees_3.sf_Quantity2;
	// 	hide Set_Up_Fees_3.sf_Total2;
}
//Computation
//Recurring Computation
vat = Global_Settings[KEY == "DEFAULT_VAT"].VALUE.toDecimal();
vat = IFNULL(vat,0.00) / 100;
if(input.sc2 == true)
{
	if(input.Service_Charges_3.count() > 0)
	{
		for each serviceItem in input.Service_Charges_3
		{
			totalServiceItem = IFNULL(serviceItem.Monthly_Service_Fee,0) * IFNULL(serviceItem.sc_Quantity2,0);
			serviceItem.sc_Total2 = totalServiceItem;
			if(serviceItem.Discount_Type.contains("Percentage"))
			{
				serviceDiscount = IFNULL(serviceItem.Discount_Amount,0) / 100;
				serviceItem.Total_Discount = serviceDiscount * totalServiceItem;
			}
			else if(serviceItem.Discount_Type.contains("Fixed"))
			{
				serviceItem.Total_Discount = IFNULL(serviceItem.Discount_Amount,0);
			}
			else
			{
				serviceItem.Total_Discount = 0;
			}
		}
	}
	//
	if(input.Set_Up_Fees_3.count() > 0)
	{
		for each setUpItem in input.Set_Up_Fees_3
		{
			totalSetUpItem = IFNULL(setUpItem.sf_Quantity2,0) * IFNULL(setUpItem.Fee,0);
			setUpItem.sf_Total2 = totalSetUpItem;
			if(setUpItem.Discount_Type.contains("Percentage"))
			{
				discount = IFNULL(setUpItem.Discount_Amount,0) / 100;
				setUpItem.Total_Discount = discount * totalSetUpItem;
			}
			else if(setUpItem.Discount_Type.contains("Fixed"))
			{
				setUpItem.Total_Discount = IFNULL(setUpItem.Discount_Amount,0);
			}
			else
			{
				setUpItem.Total_Discount = 0;
			}
		}
	}
	//
}
else if(input.sc2 == false)
{
	if(input.Service_Charges_3.count() > 0)
	{
		for each serviceItem in input.Service_Charges_3
		{
			totalServiceItem = IFNULL(serviceItem.Monthly_Service_Fee,0);
			serviceItem.sc_Total2 = totalServiceItem;
			if(serviceItem.Discount_Type.contains("Percentage"))
			{
				serviceDiscount = IFNULL(serviceItem.Discount_Amount,0) / 100;
				serviceItem.Total_Discount = serviceDiscount * totalServiceItem;
			}
			else if(serviceItem.Discount_Type.contains("Fixed"))
			{
				serviceItem.Total_Discount = IFNULL(serviceItem.Discount_Amount,0);
			}
			else
			{
				serviceItem.Total_Discount = 0;
			}
		}
	}
	//
	if(input.Set_Up_Fees_3.count() > 0)
	{
		for each setUpItem in input.Set_Up_Fees_3
		{
			totalSetUpItem = IFNULL(setUpItem.Fee,0);
			setUpItem.sf_Total2 = totalSetUpItem;
			if(setUpItem.Discount_Type.contains("Percentage"))
			{
				discount = IFNULL(setUpItem.Discount_Amount,0) / 100;
				setUpItem.Total_Discount = discount * totalSetUpItem;
			}
			else if(setUpItem.Discount_Type.contains("Fixed"))
			{
				setUpItem.Total_Discount = IFNULL(setUpItem.Discount_Amount,0);
			}
			else
			{
				setUpItem.Total_Discount = 0;
			}
		}
	}
	//
}
// Recurring
if(input.Service_Charges_3.count() > 0)
{
	totalServiceNet = 0;
	totalServiceDiscount = 0;
	for each serviceChargesData in input.Service_Charges_3
	{
		totalServiceNet += IFNULL(serviceChargesData.sc_Total2,0);
		totalServiceDiscount += IFNULL(serviceChargesData.Total_Discount,0);
	}
	totalServiceVat = totalServiceNet * vat;
	totalServiceRecurring = totalServiceNet - totalServiceDiscount;
	input.Recurring_service_charges_Net_3 = totalServiceNet;
	input.Recurring_service_charges_Discount_3 = totalServiceDiscount;
	input.recurring_Vat_3 = totalServiceVat;
	input.Recurring_service_charges_Total_3 = totalServiceRecurring + totalServiceVat;
}
// Non-recurring
//Total Set Up
totalSetUpNet = 0;
totalSetUpDiscount = 0;
if(input.Set_Up_Fees_3.count() > 0)
{
	for each setUpData in input.Set_Up_Fees_3
	{
		totalSetUpNet += IFNULL(setUpData.sf_Total2,0);
		totalSetUpDiscount += IFNULL(setUpData.Total_Discount,0);
	}
}
//Total Equipment
totalEquipmentNet = 0;
totalEqupmentDiscount = 0;
if(input.Service_Equipment_3.count() > 0)
{
	for each equipmentData in input.Service_Equipment_3
	{
		totalEquipmentNet += IFNULL(equipmentData.Total,0);
		totalEqupmentDiscount += IFNULL(equipmentData.Total_Discount,0);
	}
}
//Total Engineering
totalEngineeringNet = 0;
totalEngineeringDiscount = 0;
if(input.Service_Engineering_3.count() > 0)
{
	for each engineeringData in input.Service_Engineering_3
	{
		totalEngineeringNet += IFNULL(engineeringData.Total,0);
		totalEngineeringDiscount += IFNULL(engineeringData.Total_Discount,0);
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
