if(Service_Category_2.Category_Name.contains("Co-Location") || Service_Category_2.Category_Name.contains("IP") || Service_Category_2.Category_Name.contains("Managed Service") || Service_Category_2.Category_Name.contains("VoIP"))
{
	input.sc1 = true;
	show Service_Charges_2.sc_Quantity1;
	// 	show Service_Charges_2.sc_Total1;
	show Set_Up_Fees_2.sf_Quantity1;
	// 	show Set_Up_Fees_2.sf_Total1;
}
else
{
	input.sc1 = false;
	hide Service_Charges_2.sc_Quantity1;
	// 	hide Service_Charges_2.sc_Total1;
	hide Set_Up_Fees_2.sf_Quantity1;
	// 	hide Set_Up_Fees_2.sf_Total1;
}
//Computation
//Recurring Computation
vat = Global_Settings[KEY == "DEFAULT_VAT"].VALUE.toDecimal();
vat = IFNULL(vat,0.00) / 100;
if(input.sc1 == true)
{
	if(input.Service_Charges_2.count() > 0)
	{
		for each serviceItem in input.Service_Charges_2
		{
			totalServiceItem = IFNULL(serviceItem.Monthly_Service_Fee,0) * IFNULL(serviceItem.sc_Quantity1,0);
			serviceItem.sc_Total1 = totalServiceItem;
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
	//Set Up
	if(input.Set_Up_Fees_2.count() > 0)
	{
		for each setUpItem in input.Set_Up_Fees_2
		{
			totalSetUpItem = IFNULL(setUpItem.Fee,0) * IFNULL(setUpItem.sf_Total1,0);
			setUpItem.sf_Total1 = totalSetUpItem;
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
else if(input.sc1 == false)
{
	if(input.Service_Charges_2.count() > 0)
	{
		for each serviceItem in input.Service_Charges_2
		{
			totalServiceItem = IFNULL(serviceItem.Monthly_Service_Fee,0);
			serviceItem.sc_Total1 = totalServiceItem;
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
	//Set Up
	if(input.Set_Up_Fees_2.count() > 0)
	{
		for each setUpItem in input.Set_Up_Fees_2
		{
			totalSetUpItem = IFNULL(setUpItem.Fee,0);
			setUpItem.sf_Total1 = totalSetUpItem;
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
//
//Recurring
if(input.Service_Charges_2.count() > 0)
{
	totalServiceNet = 0;
	totalServiceDiscount = 0;
	for each serviceChargesData in input.Service_Charges_2
	{
		totalServiceNet += IFNULL(serviceChargesData.sc_Total1,0);
		totalServiceDiscount += IFNULL(serviceChargesData.Total_Discount,0);
	}
	totalServiceVat = totalServiceNet * vat;
	totalServiceRecurring = totalServiceNet - totalServiceDiscount;
	input.Recurring_service_charges_Net_2 = totalServiceNet;
	input.Recurring_service_charges_Discount_2 = totalServiceDiscount;
	input.recurring_Vat_2 = totalServiceVat;
	input.Recurring_service_charges_Total_2 = totalServiceRecurring + totalServiceVat;
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
