/*
*Show and Hide Fields in Subform
*/
if(Service_Category.Category_Name.contains("Co-Location") || Service_Category.Category_Name.contains("IP") || Service_Category.Category_Name.contains("Managed Service") || Service_Category.Category_Name.contains("VoIP"))
{
	input.sc0 = true;
	show Service_Charges.sc_Quantity0;
	// 	show Service_Charges.sc_Total0;
	show Set_Up_Fees.sf_Quantity0;
	// 	show Set_Up_Fees.sf_Total0;
}
else
{
	input.sc0 = false;
	hide Service_Charges.sc_Quantity0;
	// 	hide Service_Charges.sc_Total0;
	hide Set_Up_Fees.sf_Quantity0;
	// 	hide Set_Up_Fees.sf_Total0;
}
//Computation
//Recurring Computation
vat = Global_Settings[KEY == "DEFAULT_VAT"].VALUE.toDecimal();
vat = IFNULL(vat,0.00) / 100;
//Service Charges
if(input.sc0 == true)
{
	if(input.Service_Charges.count() > 0)
	{
		for each  serviceItem in input.Service_Charges
		{
			totalserviceItem = IFNULL(serviceItem.Monthly_Service_Fee,0.00) * IFNULL(serviceItem.sc_Quantity0,0.00);
			serviceItem.sc_Total0=totalserviceItem;
			if(serviceItem.Discount_Type.contains("Percentage"))
			{
				serviceDiscount = IFNULL(serviceItem.Discount_Amount,0) / 100;
				serviceItem.Total_Discount=serviceDiscount * totalserviceItem;
			}
			else if(serviceItem.Discount_Type.contains("Fixed"))
			{
				serviceItem.Total_Discount=IFNULL(serviceItem.Discount_Amount,0);
			}
			else
			{
				serviceItem.Total_Discount=0;
			}
		}
	}
	//
	if(input.Set_Up_Fees.count() > 0)
	{
		for each  setUpItem in input.Set_Up_Fees
		{
			totalSetUpItem = IFNULL(setUpItem.Fee,0) * IFNULL(setUpItem.sf_Quantity0,0);
			setUpItem.sf_Total0=totalSetUpItem;
			if(setUpItem.Discount_Type.contains("Percentage"))
			{
				discount = IFNULL(setUpItem.Discount_Amount,0) / 100;
				setUpItem.Total_Discount=discount * totalSetUpItem;
			}
			else if(setUpItem.Discount_Type.contains("Fixed"))
			{
				setUpItem.Total_Discount=IFNULL(setUpItem.Discount_Amount,0);
			}
			else
			{
				setUpItem.Total_Discount=0;
			}
		}
	}
}
else if(input.sc0 == false)
{
	if(input.Service_Charges.count() > 0)
	{
		for each  serviceItem in input.Service_Charges
		{
			totalserviceItem = IFNULL(serviceItem.Monthly_Service_Fee,0.00);
			serviceItem.sc_Total0=totalserviceItem;
			if(serviceItem.Discount_Type.contains("Percentage"))
			{
				serviceDiscount = IFNULL(serviceItem.Discount_Amount,0) / 100;
				serviceItem.Total_Discount=serviceDiscount * totalserviceItem;
			}
			else if(serviceItem.Discount_Type.contains("Fixed"))
			{
				serviceItem.Total_Discount=IFNULL(serviceItem.Discount_Amount,0);
			}
			else
			{
				serviceItem.Total_Discount=0;
			}
		}
	}
	//
	if(input.Set_Up_Fees.count() > 0)
	{
		for each  setUpItem in input.Set_Up_Fees
		{
			totalSetUpItem = IFNULL(setUpItem.Fee,0);
			setUpItem.sf_Total0=totalSetUpItem;
			if(setUpItem.Discount_Type.contains("Percentage"))
			{
				discount = IFNULL(setUpItem.Discount_Amount,0) / 100;
				setUpItem.Total_Discount=discount * totalSetUpItem;
			}
			else if(setUpItem.Discount_Type.contains("Fixed"))
			{
				setUpItem.Total_Discount=IFNULL(setUpItem.Discount_Amount,0);
			}
			else
			{
				setUpItem.Total_Discount=0;
			}
		}
	}
}
//Recurring
if(input.Service_Charges.count() > 0)
{
	totalServiceNet = 0;
	totalServiceDiscount = 0;
	for each  serviceChargesData in input.Service_Charges
	{
		totalServiceNet = totalServiceNet + IFNULL(serviceChargesData.sc_Total0,0);
		totalServiceDiscount = totalServiceDiscount + IFNULL(serviceChargesData.Total_Discount,0);
	}
	totalServiceVat = totalServiceNet * vat;
	totalServiceRecurring = totalServiceNet - totalServiceDiscount;
	input.Recurring_service_charge_Net = totalServiceNet;
	input.Recurring_Disount = totalServiceDiscount;
	input.recurring_Vat_1 = totalServiceVat;
	input.Recurring_service_charges_Total = totalServiceRecurring + totalServiceVat;
}
//
//Non-recurring
// Total Set Up
totalSetUpNet = 0;
totalSetUpDiscount = 0;
if(input.Set_Up_Fees.count() > 0)
{
	for each  setUpData in input.Set_Up_Fees
	{
		totalSetUpNet = totalSetUpNet + IFNULL(setUpData.sf_Total0,0);
		totalSetUpDiscount = totalSetUpDiscount + IFNULL(setUpData.Total_Discount,0);
	}
}
//Total Equipment
totalEquipmentNet = 0;
totalEqupmentDiscount = 0;
if(input.Service_Equipment.count() > 0)
{
	for each  equipmentData in input.Service_Equipment
	{
		totalEquipmentNet = totalEquipmentNet + IFNULL(equipmentData.Total,0);
		totalEqupmentDiscount = totalEqupmentDiscount + IFNULL(equipmentData.Total_Discount,0);
	}
}
//Total Engineering
totalEngineeringNet = 0;
totalEngineeringDiscount = 0;
if(input.Service_Engineering.count() > 0)
{
	for each  engineeringData in input.Service_Engineering
	{
		totalEngineeringNet = totalEngineeringNet + IFNULL(engineeringData.Total,0);
		totalEngineeringDiscount = totalEngineeringDiscount + IFNULL(engineeringData.Total_Discount,0);
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
