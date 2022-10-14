/*GENERATE Quote line items for the quote record template*/

//Service 1
//Acc Table Variab;e
acc_table = "";
acc_tableFee1 = "";
acc_tableEquipment1 = "";
acc_tableEngineering1 = "";
acc_tableCarriage1 = "";
//HTML Table Variable
html_table = "";
html_tableFee1 = "";
html_tableequipment1 = "";
html_tableEngineering1 = "";
html_tableCarriage1 = "";
//Additional Variables
service1 = 0;
carriageMap = Map();
carraigeList = List();
//
//Service Charges 1
if(input.Service_Charges.count() > 0)
{
	for each  serviceCharge1 in input.Service_Charges
	{
		acc_table = acc_table + "<tr><td style=\"width: 20%;  font-size: 10px; text-align: Left;\">" + serviceCharge1.Service.Service_Name + "</td>";
		acc_table = acc_table + "<td style=\"width: 10%; font-size: 10px; text-align: center; \">" + IFNULL(serviceCharge1.sc_Quantity0,1) + "</td>";
		acc_table = acc_table + "<td style=\"width: 10%;  font-size: 10px; text-align: center; \">" + serviceCharge1.Monthly_Service_Fee + "</td>";
		acc_table = acc_table + "<td style=\"width: 10%; font-size: 10px; text-align: center;\">" + IFNULL(serviceCharge1.sc_Total0,serviceCharge1.Monthly_Service_Fee) + "</td>";
	}
	//
	// Service Charges 1
	html_table = html_table + "<table class=\"fs\" style=\"margin: 0px left; width: 100%;\" cellspacing=\"0\"> ";
	html_table = html_table + "<thead><tr><th scope=\"col\"style=\"text-align: Left; font-weight: bold; font-size: 13px; margin-bottom:5%; width: 10%;\">Services 1 Details</th></tr></thead>";
	html_table = html_table + "<thead><tr><th scope=\"col\"style=\"text-align: Left; font-weight: bold; font-size: 12px; width: 10%;\">Services</th</tr><th scope=\"col\"style=\"text-align: center; font-weight: bold;  font-size: 12px; width: 10%;\">Quantity</th><th scope=\"col\"style=\"text-align: center; font-weight: bold; font-size: 12px; width: 10%;\">Unit Price</th><th scope=\"col\"style=\"text-align: center; font-size: 12px; font-weight: bold; width: 10%;\">Net Price</th></thead>";
	html_table = html_table + "<tbody>" + acc_table;
	html_table = html_table + "</tbody></table>";
}
//
//Set Up Fee1
if(input.Set_Up_Fees.count() > 0)
{
	for each  setUpFee1 in input.Set_Up_Fees
	{
		acc_tableFee1 = acc_tableFee1 + "<tr><td style=\"width: 20%;  font-size: 10px; text-align: Left;\">" + setUpFee1.Set_Up.Set_Up_Name + "</td>";
		acc_tableFee1 = acc_tableFee1 + "<td style=\"width: 10%; font-size: 10px; text-align: center; \">" + IFNULL(setUpFee1.sf_Quantity0,1) + "</td>";
		acc_tableFee1 = acc_tableFee1 + "<td style=\"width: 10%;  font-size: 10px; text-align: center; \">" + setUpFee1.Fee + "</td>";
		acc_tableFee1 = acc_tableFee1 + "<td style=\"width: 10%; font-size: 10px; text-align: center;\">" + IFNULL(setUpFee1.sf_Total0,setUpFee1.Fee) + "</td>";
	}
	//
	//SetUpFee1
	html_tableFee1 = html_tableFee1 + "<table class=\"fs\" style=\"margin: 0px left; width: 100%;\" cellspacing=\"0\"> ";
	html_tableFee1 = html_tableFee1 + "<thead><tr><th scope=\"col\"style=\"text-align: Left; font-weight: bold; font-size: 12px; width: 10%;\">Set Up</th</tr><th scope=\"col\"style=\"text-align: center; font-weight: bold;  font-size: 12px; width: 10%;\">Quantity</th><th scope=\"col\"style=\"text-align: center; font-weight: bold; font-size: 12px; width: 10%;\">Unit Price</th><th scope=\"col\"style=\"text-align: center; font-size: 12px; font-weight: bold; width: 10%;\">Net Price</th></thead>";
	html_tableFee1 = html_tableFee1 + "<tbody>" + acc_tableFee1;
	html_tableFee1 = html_tableFee1 + "</tbody></table>";
}
if(input.Service_Equipment.count() > 0)
{
	//
	//Equipment 1
	for each  equipment1 in input.Service_Equipment
	{
		acc_tableEquipment1 = acc_tableEquipment1 + "<tr><td style=\"width: 20%;  font-size: 10px; text-align: Left;\">" + equipment1.Equipment.Equipment_Name + "</td>";
		acc_tableEquipment1 = acc_tableEquipment1 + "<td style=\"width: 10%; font-size: 10px; text-align: center; \">" + equipment1.Quantity + "</td>";
		acc_tableEquipment1 = acc_tableEquipment1 + "<td style=\"width: 10%;  font-size: 10px; text-align: center; \">" + equipment1.Price + "</td>";
		acc_tableEquipment1 = acc_tableEquipment1 + "<td style=\"width: 10%; font-size: 10px; text-align: center;\">" + equipment1.Total + "</td>";
	}
	//
	//Equipment 1
	html_tableequipment1 = html_tableequipment1 + "<table class=\"fs\" style=\"margin: 0px left; width: 100%;\" cellspacing=\"0\"> ";
	html_tableequipment1 = html_tableequipment1 + "<thead><tr><th scope=\"col\"style=\"text-align: Left; font-weight: bold; font-size: 12px; width: 10%;\">Equipment</th</tr><th scope=\"col\"style=\"text-align: center; font-weight: bold;  font-size: 12px; width: 10%;\">Quantity</th><th scope=\"col\"style=\"text-align: center; font-weight: bold; font-size: 12px; width: 10%;\">Unit Price</th><th scope=\"col\"style=\"text-align: center; font-size: 12px; font-weight: bold; width: 10%;\">Net Price</th></thead>";
	html_tableequipment1 = html_tableequipment1 + "<tbody>" + acc_tableEquipment1;
	html_tableequipment1 = html_tableequipment1 + "</tbody></table>";
}
//Carriage
if(!input.Carriage.toString().isEmpty())
{
	//
	//Carrigae 1
	carriageMap.put("Carriage",input.Carriage);
	carraigeList.add(carriageMap);
	for each  carriageData in carraigeList
	{
		acc_tableCarriage1 = acc_tableCarriage1 + "<td style=\"width: 20%;  font-size: 10px; text-align: center;\">" + carriageData.get("Carriage") + "</td>";
	}
	//margin-left: 40%;
	//Carriage 1
	html_tableCarriage1_final = "";
	html_tableCarriage1 = html_tableCarriage1 + "<table class=\"fs\" style=\"margin: 0px left;  margin-bottom:2%; width: 100%;\" cellspacing=\"0\"> ";
	html_tableCarriage1 = html_tableCarriage1 + "<tr><th scope=\"col\"style=\"text-align: left; margin-bottom:2%; font-weight: bold; font-size: 12px; width: 80%;\">Carriage</th>";
	//
	html_tableCarriage1 = html_tableCarriage1 + acc_tableCarriage1;
	html_tableCarriage1 = html_tableCarriage1 + "</table>";
}
//
if(input.Service_Engineering.count() > 0)
{
	//
	//Engineering 1
	for each  engineering1 in input.Service_Engineering
	{
		acc_tableEngineering1 = acc_tableEngineering1 + "<tr><td style=\"width: 20%;  font-size: 10px; text-align: Left;\">" + engineering1.Engineering.Service_Name + "</td>";
		acc_tableEngineering1 = acc_tableEngineering1 + "<td style=\"width: 10%; font-size: 10px; text-align: center; \">" + engineering1.Hours + "</td>";
		acc_tableEngineering1 = acc_tableEngineering1 + "<td style=\"width: 10%;  font-size: 10px; text-align: center; \">" + engineering1.Rate + "</td>";
		acc_tableEngineering1 = acc_tableEngineering1 + "<td style=\"width: 10%; font-size: 10px; text-align: center;\">" + engineering1.Total + "</td>";
	}
	//
	//Engineering
	html_tableEngineering1 = html_tableEngineering1 + "<table class=\"fs\" style=\"margin: 0px left; width: 100%;\" cellspacing=\"0\"> ";
	html_tableEngineering1 = html_tableEngineering1 + "<thead><tr><th scope=\"col\"style=\"text-align: Left; font-weight: bold; font-size: 12px; width: 10%;\">Engineering</th</tr><th scope=\"col\"style=\"text-align: center; font-weight: bold;  font-size: 12px; width: 10%;\">Hour</th><th scope=\"col\"style=\"text-align: center; font-weight: bold; font-size: 12px; width: 10%;\">Rate</th><th scope=\"col\"style=\"text-align: center; font-size: 12px; font-weight: bold; width: 10%;\">Net Price</th></thead>";
	html_tableEngineering1 = html_tableEngineering1 + "<tbody>" + acc_tableEngineering1;
	html_tableEngineering1 = html_tableEngineering1 + "</tbody></table>";
}
///
///
///Service 2
//Service 2
//Acc Table Variab;e
acc_table2 = "";
acc_tableFee2 = "";
acc_tableEquipment2 = "";
acc_tableEngineering2 = "";
acc_tableCarriage2 = "";
//HTML Table Variable
html_table2 = "";
html_tableFee2 = "";
html_tableequipment2 = "";
html_tableEngineering2 = "";
html_tableCarriage2 = "";
//Additional Variables
carriageMap2 = Map();
carraigeList2 = List();
//
//Service Charges 
if(input.Service_Charges_2.count() > 0)
{
	for each  serviceCharge2 in input.Service_Charges_2
	{
		acc_table2 = acc_table2 + "<tr><td style=\"width: 20%;  font-size: 10px; text-align: Left;\">" + serviceCharge2.Service.Service_Name + "</td>";
		acc_table2 = acc_table2 + "<td style=\"width: 10%; font-size: 10px; text-align: center; \">" + IFNULL(serviceCharge2.sc_Quantity1,1) + "</td>";
		acc_table2 = acc_table2 + "<td style=\"width: 10%;  font-size: 10px; text-align: center; \">" + serviceCharge2.Monthly_Service_Fee + "</td>";
		acc_table2 = acc_table2 + "<td style=\"width: 10%; font-size: 10px; text-align: center;\">" + IFNULL(serviceCharge2.sc_Total1,serviceCharge2.Monthly_Service_Fee) + "</td>";
	}
	//page-break-before: always;
	// Service Charges 
	html_table2 = html_table2 + "<table class=\"fs\" style=\"margin: 0px left;  border-top: 5px solid; width: 100%;\" cellspacing=\"0\"> ";
	html_table2 = html_table2 + "<thead><tr><th scope=\"col\"style=\"text-align: Left; font-weight: bold; font-size: 13px; margin-bottom:5%; width: 10%;\">Services 2 Details</th></tr></thead>";
	html_table2 = html_table2 + "<thead><tr><th scope=\"col\"style=\"text-align: Left; font-weight: bold; font-size: 12px; width: 10%;\">Services</th</tr><th scope=\"col\"style=\"text-align: center; font-weight: bold;  font-size: 12px; width: 10%;\">Quantity</th><th scope=\"col\"style=\"text-align: center; font-weight: bold; font-size: 12px; width: 10%;\">Unit Price</th><th scope=\"col\"style=\"text-align: center; font-size: 12px; font-weight: bold; width: 10%;\">Net Price</th></thead>";
	html_table2 = html_table2 + "<tbody>" + acc_table2;
	html_table2 = html_table2 + "</tbody></table>";
}
//
//Set Up Fee
if(input.Set_Up_Fees_2.count() > 0)
{
	for each  setUpFee2 in input.Set_Up_Fees_2
	{
		acc_tableFee2 = acc_tableFee2 + "<tr><td style=\"width: 20%;  font-size: 10px; text-align: Left;\">" + setUpFee2.Set_Up.Set_Up_Name + "</td>";
		acc_tableFee2 = acc_tableFee2 + "<td style=\"width: 10%; font-size: 10px; text-align: center; \">" + IFNULL(setUpFee2.sf_Quantity1,1) + "</td>";
		acc_tableFee2 = acc_tableFee2 + "<td style=\"width: 10%;  font-size: 10px; text-align: center; \">" + setUpFee2.Fee + "</td>";
		acc_tableFee2 = acc_tableFee2 + "<td style=\"width: 10%; font-size: 10px; text-align: center;\">" + IFNULL(setUpFee2.sf_Total1,setUpFee2.Fee) + "</td>";
	}
	//
	//SetUpFee
	html_tableFee2 = html_tableFee2 + "<table class=\"fs\" style=\"margin: 0px left; width: 100%;\" cellspacing=\"0\"> ";
	html_tableFee2 = html_tableFee2 + "<thead><tr><th scope=\"col\"style=\"text-align: Left; font-weight: bold; font-size: 12px; width: 10%;\">Set Up</th</tr><th scope=\"col\"style=\"text-align: center; font-weight: bold;  font-size: 12px; width: 10%;\">Quantity</th><th scope=\"col\"style=\"text-align: center; font-weight: bold; font-size: 12px; width: 10%;\">Unit Price</th><th scope=\"col\"style=\"text-align: center; font-size: 12px; font-weight: bold; width: 10%;\">Net Price</th></thead>";
	html_tableFee2 = html_tableFee2 + "<tbody>" + acc_tableFee2;
	html_tableFee2 = html_tableFee2 + "</tbody></table>";
}
if(input.Service_Equipment_2.count() > 0)
{
	//
	//Equipment 
	for each  equipment2 in input.Service_Equipment_2
	{
		acc_tableEquipment2 = acc_tableEquipment2 + "<tr><td style=\"width: 20%;  font-size: 10px; text-align: Left;\">" + equipment2.Equipment.Equipment_Name + "</td>";
		acc_tableEquipment2 = acc_tableEquipment2 + "<td style=\"width: 10%; font-size: 10px; text-align: center; \">" + equipment2.Quantity + "</td>";
		acc_tableEquipment2 = acc_tableEquipment2 + "<td style=\"width: 10%;  font-size: 10px; text-align: center; \">" + equipment2.Price + "</td>";
		acc_tableEquipment2 = acc_tableEquipment2 + "<td style=\"width: 10%; font-size: 10px; text-align: center;\">" + equipment2.Total + "</td>";
	}
	//
	//Equipment 
	html_tableequipment2 = html_tableequipment2 + "<table class=\"fs\" style=\"margin: 0px left; width: 100%;\" cellspacing=\"0\"> ";
	html_tableequipment2 = html_tableequipment2 + "<thead><tr><th scope=\"col\"style=\"text-align: Left; font-weight: bold; font-size: 12px; width: 10%;\">Equipment</th</tr><th scope=\"col\"style=\"text-align: center; font-weight: bold;  font-size: 12px; width: 10%;\">Quantity</th><th scope=\"col\"style=\"text-align: center; font-weight: bold; font-size: 12px; width: 10%;\">Unit Price</th><th scope=\"col\"style=\"text-align: center; font-size: 12px; font-weight: bold; width: 10%;\">Net Price</th></thead>";
	html_tableequipment2 = html_tableequipment2 + "<tbody>" + acc_tableEquipment2;
	html_tableequipment2 = html_tableequipment2 + "</tbody></table>";
}
//Carriage2
if(!input.Carriage_2.toString().isEmpty())
{
	//
	//Carrigae 
	carriageMap2.put("Carriage",input.Carriage_2);
	carraigeList2.add(carriageMap2);
	for each  carriageData2 in carraigeList2
	{
		acc_tableCarriage2 = acc_tableCarriage2 + "<td style=\"width: 20%;  font-size: 10px; text-align: center;\">" + carriageData2.get("Carriage") + "</td>";
	}
	//
	//Carriage
	html_tableCarriage2 = html_tableCarriage2 + "<table class=\"fs\" style=\"margin: 0px left;  margin-bottom:2%; width: 100%;\" cellspacing=\"0\"> ";
	html_tableCarriage2 = html_tableCarriage2 + "<tr><th scope=\"col\"style=\"text-align: left; margin-bottom:2%; font-weight: bold; font-size: 12px; width: 80%;\">Carriage</th>";
	//
	html_tableCarriage2 = html_tableCarriage2 + acc_tableCarriage2;
	html_tableCarriage2 = html_tableCarriage2 + "</table>";
}
if(input.Service_Engineering_2.count() > 0)
{
	//
	//Engineering 
	for each  engineering2 in input.Service_Engineering_2
	{
		acc_tableEngineering2 = acc_tableEngineering2 + "<tr><td style=\"width: 20%;  font-size: 10px; text-align: Left;\">" + engineering1.Engineering.Service_Name + "</td>";
		acc_tableEngineering2 = acc_tableEngineering2 + "<td style=\"width: 10%; font-size: 10px; text-align: center; \">" + engineering2.Hours + "</td>";
		acc_tableEngineering2 = acc_tableEngineering2 + "<td style=\"width: 10%;  font-size: 10px; text-align: center; \">" + engineering2.Rate + "</td>";
		acc_tableEngineering2 = acc_tableEngineering2 + "<td style=\"width: 10%; font-size: 10px; text-align: center;\">" + engineering2.Total + "</td>";
	}
	//
	//Engineering
	html_tableEngineering2 = html_tableEngineering2 + "<table class=\"fs\" style=\"margin: 0px left; width: 100%;\" cellspacing=\"0\"> ";
	html_tableEngineering2 = html_tableEngineering2 + "<thead><tr><th scope=\"col\"style=\"text-align: Left; font-weight: bold; font-size: 12px; width: 10%;\">Engineering</th</tr><th scope=\"col\"style=\"text-align: center; font-weight: bold;  font-size: 12px; width: 10%;\">Hour</th><th scope=\"col\"style=\"text-align: center; font-weight: bold; font-size: 12px; width: 10%;\">Rate</th><th scope=\"col\"style=\"text-align: center; font-size: 12px; font-weight: bold; width: 10%;\">Net Price</th></thead>";
	html_tableEngineering2 = html_tableEngineering2 + "<tbody>" + acc_tableEngineering2;
	html_tableEngineering2 = html_tableEngineering2 + "</tbody></table>";
}
//
//
//Service 3
//Service 3
//Acc Table Variab;e
acc_table3 = "";
acc_tableFee3 = "";
acc_tableEquipment3 = "";
acc_tableEngineering3 = "";
acc_tableCarriage3 = "";
//HTML Table Variable
html_table3 = "";
html_tableFee3 = "";
html_tableequipment3 = "";
html_tableEngineering3 = "";
html_tableCarriage3 = "";
//Additional Variables
carriageMap3 = Map();
carraigeList3 = List();
//
//Service Charges 
if(input.Service_Charges_3.count() > 0)
{
	for each  serviceCharge3 in input.Service_Charges_3
	{
		acc_table3 = acc_table3 + "<tr><td style=\"width: 20%;  font-size: 10px; text-align: Left;\">" + serviceCharge3.Service.Service_Name + "</td>";
		acc_table3 = acc_table3 + "<td style=\"width: 10%; font-size: 10px; text-align: center; \">" + IFNULL(serviceCharge3.sc_Quantity2,1) + "</td>";
		acc_table3 = acc_table3 + "<td style=\"width: 10%;  font-size: 10px; text-align: center; \">" + serviceCharge3.Monthly_Service_Fee + "</td>";
		acc_table3 = acc_table3 + "<td style=\"width: 10%; font-size: 10px; text-align: center;\">" + IFNULL(serviceCharge3.sc_Total2,serviceCharge3.Monthly_Service_Fee) + "</td>";
	}
	//page-break-before: always;
	// Service Charges 
	html_table3 = html_table3 + "<table class=\"fs\" style=\"margin: 0px left; margin-top:1%; page-break-before: always; border-top: 5px solid; width: 100%;\" cellspacing=\"0\"> ";
	html_table3 = html_table3 + "<thead><tr><th scope=\"col\"style=\"text-align: Left; font-weight: bold; font-size: 13px; margin-bottom:5%; width: 10%;\">Services 3 Details</th></tr></thead>";
	html_table3 = html_table3 + "<thead><tr><th scope=\"col\"style=\"text-align: Left; font-weight: bold; font-size: 12px; width: 10%;\">Services</th</tr><th scope=\"col\"style=\"text-align: center; font-weight: bold;  font-size: 12px; width: 10%;\">Quantity</th><th scope=\"col\"style=\"text-align: center; font-weight: bold; font-size: 12px; width: 10%;\">Unit Price</th><th scope=\"col\"style=\"text-align: center; font-size: 12px; font-weight: bold; width: 10%;\">Net Price</th></thead>";
	html_table3 = html_table3 + "<tbody>" + acc_table3;
	html_table3 = html_table3 + "</tbody></table>";
}
//
//Set Up Fee
if(input.Set_Up_Fees_3.count() > 0)
{
	for each  setUpFee3 in input.Set_Up_Fees_3
	{
		acc_tableFee3 = acc_tableFee3 + "<tr><td style=\"width: 20%;  font-size: 10px; text-align: Left;\">" + setUpFee3.Set_Up.Set_Up_Name + "</td>";
		acc_tableFee3 = acc_tableFee3 + "<td style=\"width: 10%; font-size: 10px; text-align: center; \">" + IFNULL(setUpFee3.sf_Quantity2,1) + "</td>";
		acc_tableFee3 = acc_tableFee3 + "<td style=\"width: 10%;  font-size: 10px; text-align: center; \">" + setUpFee3.Fee + "</td>";
		acc_tableFee3 = acc_tableFee3 + "<td style=\"width: 10%; font-size: 10px; text-align: center;\">" + IFNULL(setUpFee3.sf_Total2,setUpFee3.Fee) + "</td>";
	}
	//
	//SetUpFee
	html_tableFee3 = html_tableFee3 + "<table class=\"fs\" style=\"margin: 0px left; width: 100%;\" cellspacing=\"0\"> ";
	html_tableFee3 = html_tableFee3 + "<thead><tr><th scope=\"col\"style=\"text-align: Left; font-weight: bold; font-size: 12px; width: 10%;\">Set Up</th</tr><th scope=\"col\"style=\"text-align: center; font-weight: bold;  font-size: 12px; width: 10%;\">Quantity</th><th scope=\"col\"style=\"text-align: center; font-weight: bold; font-size: 12px; width: 10%;\">Unit Price</th><th scope=\"col\"style=\"text-align: center; font-size: 12px; font-weight: bold; width: 10%;\">Net Price</th></thead>";
	html_tableFee3 = html_tableFee3 + "<tbody>" + acc_tableFee3;
	html_tableFee3 = html_tableFee3 + "</tbody></table>";
}
if(input.Service_Equipment_3.count() > 0)
{
	//
	//Equipment 
	for each  equipment3 in input.Service_Equipment_3
	{
		acc_tableEquipment3 = acc_tableEquipment3 + "<tr><td style=\"width: 20%;  font-size: 10px; text-align: Left;\">" + equipment3.Equipment.Equipment_Name + "</td>";
		acc_tableEquipment3 = acc_tableEquipment3 + "<td style=\"width: 10%; font-size: 10px; text-align: center; \">" + equipment3.Quantity + "</td>";
		acc_tableEquipment3 = acc_tableEquipment3 + "<td style=\"width: 10%;  font-size: 10px; text-align: center; \">" + equipment3.Price + "</td>";
		acc_tableEquipment3 = acc_tableEquipment3 + "<td style=\"width: 10%; font-size: 10px; text-align: center;\">" + equipment3.Total + "</td>";
	}
	//
	//Equipment 
	html_tableequipment3 = html_tableequipment3 + "<table class=\"fs\" style=\"margin: 0px left; width: 100%;\" cellspacing=\"0\"> ";
	html_tableequipment3 = html_tableequipment3 + "<thead><tr><th scope=\"col\"style=\"text-align: Left; font-weight: bold; font-size: 12px; width: 10%;\">Equipment</th</tr><th scope=\"col\"style=\"text-align: center; font-weight: bold;  font-size: 12px; width: 10%;\">Quantity</th><th scope=\"col\"style=\"text-align: center; font-weight: bold; font-size: 12px; width: 10%;\">Unit Price</th><th scope=\"col\"style=\"text-align: center; font-size: 12px; font-weight: bold; width: 10%;\">Net Price</th></thead>";
	html_tableequipment3 = html_tableequipment3 + "<tbody>" + acc_tableEquipment3;
	html_tableequipment3 = html_tableequipment3 + "</tbody></table>";
}
//Carriage 3
if(!input.Carriage_3.toString().isEmpty())
{
	//
	//Carrigae 
	carriageMap3.put("Carriage",input.Carriage_3);
	carraigeList3.add(carriageMap3);
	for each  carriageData3 in carraigeList3
	{
		acc_tableCarriage3 = acc_tableCarriage3 + "<td style=\"width: 20%;  font-size: 10px; text-align: center;\">" + carriageData3.get("Carriage") + "</td>";
	}
	//
	//Carriage 
	//
	html_tableCarriage3 = html_tableCarriage3 + "<table class=\"fs\" style=\"margin: 0px left;  margin-bottom:2%; width: 100%;\" cellspacing=\"0\"> ";
	html_tableCarriage3 = html_tableCarriage3 + "<tr><th scope=\"col\"style=\"text-align: left; margin-bottom:2%; font-weight: bold; font-size: 12px; width: 80%;\">Carriage</th>";
	//
	html_tableCarriage3 = html_tableCarriage3 + acc_tableCarriage3;
	html_tableCarriage3 = html_tableCarriage3 + "</table>";
}
if(input.Service_Engineering_3.count() > 0)
{
	//
	//Engineering 
	for each  engineering3 in input.Service_Engineering_3
	{
		acc_tableEngineering3 = acc_tableEngineering3 + "<tr><td style=\"width: 20%;  font-size: 10px; text-align: Left;\">" + engineering3.Engineering.Service_Name + "</td>";
		acc_tableEngineering3 = acc_tableEngineering3 + "<td style=\"width: 10%; font-size: 10px; text-align: center; \">" + engineering3.Hours + "</td>";
		acc_tableEngineering3 = acc_tableEngineering3 + "<td style=\"width: 10%;  font-size: 10px; text-align: center; \">" + engineering3.Rate + "</td>";
		acc_tableEngineering3 = acc_tableEngineering3 + "<td style=\"width: 10%; font-size: 10px; text-align: center;\">" + engineering3.Total + "</td>";
	}
	//
	//Engineering
	html_tableEngineering3 = html_tableEngineering3 + "<table class=\"fs\" style=\"margin: 0px left; width: 100%;\" cellspacing=\"0\"> ";
	html_tableEngineering3 = html_tableEngineering3 + "<thead><tr><th scope=\"col\"style=\"text-align: Left; font-weight: bold; font-size: 12px; width: 10%;\">Engineering</th</tr><th scope=\"col\"style=\"text-align: center; font-weight: bold;  font-size: 12px; width: 10%;\">Hour</th><th scope=\"col\"style=\"text-align: center; font-weight: bold; font-size: 12px; width: 10%;\">Rate</th><th scope=\"col\"style=\"text-align: center; font-size: 12px; font-weight: bold; width: 10%;\">Net Price</th></thead>";
	html_tableEngineering3 = html_tableEngineering3 + "<tbody>" + acc_tableEngineering3;
	html_tableEngineering3 = html_tableEngineering3 + "</tbody></table>";
}
//
//
//Service 4
//Acc Table Variab;e
acc_table4 = "";
acc_tableFee4 = "";
acc_tableEquipment4 = "";
acc_tableEngineering4 = "";
acc_tableCarriage4 = "";
//HTML Table Variable
html_table4 = "";
html_tableFee4 = "";
html_tableequipment4 = "";
html_tableEngineering4 = "";
html_tableCarriage4 = "";
//Additional Variables
carriageMap4 = Map();
carraigeList4 = List();
//
//Service Charges 
if(input.Service_Charges_4.count() > 0)
{
	for each  serviceCharge4 in input.Service_Charges_4
	{
		acc_table4 = acc_table4 + "<tr><td style=\"width: 20%;  font-size: 10px; text-align: Left;\">" + serviceCharge4.Service.Service_Name + "</td>";
		acc_table4 = acc_table4 + "<td style=\"width: 10%; font-size: 10px; text-align: center; \">" + IFNULL(serviceCharge4.sc_Quantity3,1) + "</td>";
		acc_table4 = acc_table4 + "<td style=\"width: 10%;  font-size: 10px; text-align: center; \">" + serviceCharge4.Monthly_Service_Fee + "</td>";
		acc_table4 = acc_table4 + "<td style=\"width: 10%; font-size: 10px; text-align: center;\">" + IFNULL(serviceCharge4.sc_Total3,serviceCharge4.Monthly_Service_Fee) + "</td>";
	}
	//
	// Service Charges 
	html_table4 = html_table4 + "<table class=\"fs\" style=\"margin: 0px left; border-top: 5px solid; width: 100%;\" cellspacing=\"0\"> ";
	html_table4 = html_table4 + "<thead><tr><th scope=\"col\"style=\"text-align: Left; font-weight: bold; font-size: 13px; margin-bottom:5%; width: 10%;\">Services 4 Details</th></tr></thead>";
	html_table4 = html_table4 + "<thead><tr><th scope=\"col\"style=\"text-align: Left; font-weight: bold; font-size: 12px; width: 10%;\">Services</th</tr><th scope=\"col\"style=\"text-align: center; font-weight: bold;  font-size: 12px; width: 10%;\">Quantity</th><th scope=\"col\"style=\"text-align: center; font-weight: bold; font-size: 12px; width: 10%;\">Unit Price</th><th scope=\"col\"style=\"text-align: center; font-size: 12px; font-weight: bold; width: 10%;\">Net Price</th></thead>";
	html_table4 = html_table4 + "<tbody>" + acc_table4;
	html_table4 = html_table4 + "</tbody></table>";
}
//
//Set Up Fee
if(input.Set_Up_Fees_4.count() > 0)
{
	for each  setUpFee4 in input.Set_Up_Fees_4
	{
		acc_tableFee4 = acc_tableFee4 + "<tr><td style=\"width: 20%;  font-size: 10px; text-align: Left;\">" + setUpFee4.Set_Up.Set_Up_Name + "</td>";
		acc_tableFee4 = acc_tableFee4 + "<td style=\"width: 10%; font-size: 10px; text-align: center; \">" + IFNULL(setUpFee4.sf_Quantity3,1) + "</td>";
		acc_tableFee4 = acc_tableFee4 + "<td style=\"width: 10%;  font-size: 10px; text-align: center; \">" + setUpFee4.Fee + "</td>";
		acc_tableFee4 = acc_tableFee4 + "<td style=\"width: 10%; font-size: 10px; text-align: center;\">" + IFNULL(setUpFee4.sf_Total3,setUpFee4.Fee) + "</td>";
	}
	//
	//SetUpFee
	html_tableFee4 = html_tableFee4 + "<table class=\"fs\" style=\"margin: 0px left; width: 100%;\" cellspacing=\"0\"> ";
	html_tableFee4 = html_tableFee4 + "<thead><tr><th scope=\"col\"style=\"text-align: Left; font-weight: bold; font-size: 12px; width: 10%;\">Set Up</th</tr><th scope=\"col\"style=\"text-align: center; font-weight: bold;  font-size: 12px; width: 10%;\">Quantity</th><th scope=\"col\"style=\"text-align: center; font-weight: bold; font-size: 12px; width: 10%;\">Unit Price</th><th scope=\"col\"style=\"text-align: center; font-size: 12px; font-weight: bold; width: 10%;\">Net Price</th></thead>";
	html_tableFee4 = html_tableFee4 + "<tbody>" + acc_tableFee4;
	html_tableFee4 = html_tableFee4 + "</tbody></table>";
}
if(input.Service_Equipment_4.count() > 0)
{
	//
	//Equipment 
	for each  equipment4 in input.Service_Equipment_4
	{
		acc_tableEquipment4 = acc_tableEquipment4 + "<tr><td style=\"width: 20%;  font-size: 10px; text-align: Left;\">" + equipment4.Equipment.Equipment_Name + "</td>";
		acc_tableEquipment4 = acc_tableEquipment4 + "<td style=\"width: 10%; font-size: 10px; text-align: center; \">" + equipment4.Quantity + "</td>";
		acc_tableEquipment4 = acc_tableEquipment4 + "<td style=\"width: 10%;  font-size: 10px; text-align: center; \">" + equipment4.Price + "</td>";
		acc_tableEquipment4 = acc_tableEquipment4 + "<td style=\"width: 10%; font-size: 10px; text-align: center;\">" + equipment4.Total + "</td>";
	}
	//
	//Equipment 
	html_tableequipment4 = html_tableequipment4 + "<table class=\"fs\" style=\"margin: 0px left; width: 100%;\" cellspacing=\"0\"> ";
	html_tableequipment4 = html_tableequipment4 + "<thead><tr><th scope=\"col\"style=\"text-align: Left; font-weight: bold; font-size: 12px; width: 10%;\">Equipment</th</tr><th scope=\"col\"style=\"text-align: center; font-weight: bold;  font-size: 12px; width: 10%;\">Quantity</th><th scope=\"col\"style=\"text-align: center; font-weight: bold; font-size: 12px; width: 10%;\">Unit Price</th><th scope=\"col\"style=\"text-align: center; font-size: 12px; font-weight: bold; width: 10%;\">Net Price</th></thead>";
	html_tableequipment4 = html_tableequipment4 + "<tbody>" + acc_tableEquipment4;
	html_tableequipment4 = html_tableequipment4 + "</tbody></table>";
}
//Carriage4
if(!input.Carriage_4.toString().isEmpty())
{
	//
	//Carrigae 
	carriageMap4.put("Carriage",input.Carriage_4);
	carraigeList4.add(carriageMap4);
	for each  carriageData4 in carraigeList4
	{
		acc_tableCarriage4 = acc_tableCarriage4 + "<td style=\"width: 20%;  font-size: 10px; text-align: center;\">" + carriageData4.get("Carriage") + "</td>";
	}
	//
	//Carriage 
	html_tableCarriage4 = html_tableCarriage4 + "<table class=\"fs\" style=\"margin: 0px left;  margin-bottom:2%; width: 100%;\" cellspacing=\"0\"> ";
	html_tableCarriage4 = html_tableCarriage4 + "<tr><th scope=\"col\"style=\"text-align: left; margin-bottom:2%; font-weight: bold; font-size: 12px; width: 80%;\">Carriage</th>";
	//
	html_tableCarriage4 = html_tableCarriage4 + acc_tableCarriage4;
	html_tableCarriage4 = html_tableCarriage4 + "</table>";
}
if(input.Service_Engineering_4.count() > 0)
{
	//
	//Engineering 
	for each  engineering4 in input.Service_Engineering_4
	{
		acc_tableEngineering4 = acc_tableEngineering4 + "<tr><td style=\"width: 20%;  font-size: 10px; text-align: Left;\">" + engineering4.Engineering.Service_Name + "</td>";
		acc_tableEngineering4 = acc_tableEngineering4 + "<td style=\"width: 10%; font-size: 10px; text-align: center; \">" + engineering4.Hours + "</td>";
		acc_tableEngineering4 = acc_tableEngineering4 + "<td style=\"width: 10%;  font-size: 10px; text-align: center; \">" + engineering4.Rate + "</td>";
		acc_tableEngineering4 = acc_tableEngineering4 + "<td style=\"width: 10%; font-size: 10px; text-align: center;\">" + engineering4.Total + "</td>";
	}
	//
	//Engineering
	html_tableEngineering4 = html_tableEngineering4 + "<table class=\"fs\" style=\"margin: 0px left; width: 100%;\" cellspacing=\"0\"> ";
	html_tableEngineering4 = html_tableEngineering4 + "<thead><tr><th scope=\"col\"style=\"text-align: Left; font-weight: bold; font-size: 12px; width: 10%;\">Engineering</th</tr><th scope=\"col\"style=\"text-align: center; font-weight: bold;  font-size: 12px; width: 10%;\">Hour</th><th scope=\"col\"style=\"text-align: center; font-weight: bold; font-size: 12px; width: 10%;\">Rate</th><th scope=\"col\"style=\"text-align: center; font-size: 12px; font-weight: bold; width: 10%;\">Net Price</th></thead>";
	html_tableEngineering4 = html_tableEngineering4 + "<tbody>" + acc_tableEngineering4;
	html_tableEngineering4 = html_tableEngineering4 + "</tbody></table>";
}
//
//
//Discount
acc_discount = "";
//HTML Table Variable
html_discount = "";
//Additional Variables
discountMaps = Map();
finalDiscountLists = Collection();
input.All_Discount_Reason = input.Monthly_Discount_Reason + "<br>" + input.Upfront_Discount_Reason;
input.All_Discount = input.Monthly_Discount_Total.toString() + "<br>" + input.Upfront_Discount_Total;
discountMaps.put("Reason",input.All_Discount_Reason);
discountMaps.put("Discounts",input.All_Discount);
finalDiscountLists.insert(discountMaps);
for each  discountData in finalDiscountLists
{
	acc_discount = acc_discount + "<tr><td style=\"width: 20%;  font-size: 10px; text-align: Left;\">" + IFNULL(discountData.get("Reason"),"") + "</td>";
	acc_discount = acc_discount + "<td style=\"width: 10%; font-size: 10px; text-align: center; \">" + IFNULL(discountData.get("Discounts"),"") + "</td>";
}
html_discount = html_discount + "<table class=\"fs\" style=\"margin: 0px left; border-top: 5px solid; width: 100%;\" cellspacing=\"0\"> ";
html_discount = html_discount + "<thead><tr><th scope=\"col\"style=\"text-align: Left; font-weight: bold; font-size: 13px; margin-bottom:5%; width: 10%;\">Discount</th></tr></thead>";
html_discount = html_discount + "<thead><tr><th scope=\"col\"style=\"text-align: Left; font-weight: bold; font-size: 12px; width: 10%;\">Reason For Discount</th</tr><th scope=\"col\"style=\"text-align: center; font-weight: bold;  font-size: 12px; width: 10%;\">Total Discount</th></thead>";
html_discount = html_discount + "<tbody>" + acc_discount;
html_discount = html_discount + "</tbody></table>";
//
//Net Amount
input.Net_Amount = IFNULL(input.Total_Upfront_Fee,0) + IFNULL(input.Total_Monthly_Service_Charges,0);
//
//Final assignment
//
//
finalHtml1 = html_table + "<br>" + html_tableFee1 + "<br>" + html_tableequipment1 + "<br>" + html_tableCarriage1 + html_tableEngineering1;
finalHtml2 = html_table2 + "<br>" + html_tableFee2 + "<br>" + html_tableequipment2 + "<br>" + html_tableCarriage2 + html_tableEngineering2;
finalHtml3 = html_table3 + "<br>" + html_tableFee3 + "<br>" + html_tableequipment3 + "<br>" + html_tableCarriage3 + html_tableEngineering3;
finalHtml4 = html_table4 + "<br>" + html_tableFee4 + "<br>" + html_tableequipment4 + "<br>" + html_tableCarriage4 + html_tableEngineering4;
//Final assignment
input.Service_One_Line_Items_Template = finalHtml1 + "<br>" + finalHtml2 + "<br>" + finalHtml3 + "<br>" + finalHtml4 + "<br>" + html_discount;
