//GET CRM VALUE
crmResponse = zoho.crm.getRecordById("Accounts",input.Company.toLong());
// //Field Mapping 
//Local Variable
creatorMaps = Map();
quoteIDmaps = Map();
quoteNumberMaps = Map();
quoteIDLists = List();
service1List = List();
// Service1List Varible is being used for all the line items from Service1 to Service 4 and mapped to inventory 
if(crmResponse != null)
{
	creatorMaps.put("customer_id",crmResponse.get("ZInventory_Customer_ID"));
}
//Inventory Custom Fields
//Quote ID
quoteIDmaps.put("api_name","cf_quote_id");
quoteIDmaps.put("value",input.ID);
//Quote Reference Code
quoteNumberMaps.put("api_name","cf_quote_reference_code");
quoteNumberMaps.put("value",input.Quote_Number);
quoteIDLists.add(quoteIDmaps);
quoteIDLists.add(quoteNumberMaps);
creatorMaps.put("custom_fields",quoteIDLists);
//
/** Service Details 1 **/
//Service Charge 1
service1CfList = List();
if(input.Service_Charges.count() > 0)
{
	for each  service1 in input.Service_Charges
	{
		service1Maps = Map();
		service1Category = Map();
		service1Code = Map();
		// service1Maps.put("item_id", IFNULL(service1.Service.Inventory_ID,0));
		service1Maps.put("name",IFNULL(service1.Service.Service_Name,""));
		service1Maps.put("quantity",IFNULL(service1.sc_Quantity0,1));
		service1Maps.put("rate",IFNULL(service1.Monthly_Service_Fee,0));
		service1Maps.put("tax_id",253658000000170015);
		if(service1.Service.Ad_hoc == true)
		{
			service1Code.put("api_name","cf_product_service_code");
			service1Code.put("value",service1.Service.Product_Code_Services);
			service1Category.put("api_name","cf_product_services_category");
			service1Category.put("value",service1.Service.Product_Service_Category);
			service1CfList.add(service1Category);
			service1CfList.add(service1Code);
		}
		service1Maps.put("item_custom_fields",service1CfList);
		service1List.add(service1Maps);
	}
}
//Set Up 1 
setUp1CFList = List();
if(input.Set_Up_Fees.count() > 0)
{
	for each  setUp1 in input.Set_Up_Fees
	{
		setUp1Maps = Map();
		setUp1Code = Map();
		setUp1Category = Map();
		//Mapping
		setUp1Maps.put("name",IFNULL(setUp1.Set_Up.Set_Up_Name,""));
		setUp1Maps.put("quantity",IFNULL(setUp1.sf_Quantity0,1));
		setUp1Maps.put("rate",IFNULL(setUp1.Fee,0));
		setUp1Maps.put("tax_id",253658000000170015);
		if(setUp1.Set_Up.Ad_hoc == true)
		{
			setUp1Code.put("api_name","cf_product_service_code");
			setUp1Code.put("value",setUp1.Set_Up.Product_Code_SetUp);
			setUp1Category.put("api_name","cf_product_services_category");
			setUp1Category.put("value",setUp1.Set_Up.Product_Service_Category);
			setUp1CFList.add(setUp1Category);
			setUp1CFList.add(setUp1Code);
		}
		setUp1Maps.put("item_custom_fields",setUp1CFList);
		service1List.add(setUp1Maps);
	}
}
//Equipment 1
equipment1CFList = List();
if(input.Service_Equipment.count() > 0)
{
	for each  equipment1 in input.Service_Equipment
	{
		equipment1Maps = Map();
		equipment1Code = Map();
		equipment1Category = Map();
		//Mapping
		equipment1Maps.put("name",IFNULL(equipment1.Equipment.Equipment_Name,""));
		equipment1Maps.put("quantity",IFNULL(equipment1.Quantity,1));
		equipment1Maps.put("rate",IFNULL(equipment1.Price,0));
		equipment1Maps.put("tax_id",253658000000170015);
		if(equipment1.Equipment.Ad_Hoc == true)
		{
			equipment1Code.put("api_name","cf_product_service_code");
			equipment1Code.put("value",IFNULL(equipment1.Equipment.Equipment_Code,""));
			equipment1Category.put("api_name","cf_product_services_category");
			equipment1Category.put("value",IFNULL(equipment1.Equipment.Product_Service_Category,""));
			equipment1CFList.add(equipment1Category);
			equipment1CFList.add(equipment1Code);
		}
		equipment1Maps.put("item_custom_fields",equipment1CFList);
		service1List.add(equipment1Maps);
	}
}
//Engineering 1
engineering1CFList = List();
if(input.Service_Engineering.count() > 0)
{
	for each  engineering1 in input.Service_Engineering
	{
		engineering1Maps = Map();
		engineering1Code = Map();
		engineering1Category = Map();
		//Mapping
		engineering1Maps.put("name",IFNULL(engineering1.Engineering.Service_Name,""));
		engineering1Maps.put("quantity",IFNULL(engineering1.Hours,1));
		engineering1Maps.put("rate",IFNULL(engineering1.Rate,0));
		engineering1Maps.put("tax_id",253658000000170015);
		if(engineering1.Engineering.Ad_hoc == true)
		{
			engineering1Code.put("api_name","cf_product_service_code");
			engineering1Code.put("value",IFNULL(engineering1.Engineering.Product_Code_Engineering,""));
			engineering1Category.put("api_name","cf_product_services_category");
			engineering1Category.put("value",IFNULL(engineering1.Engineering.Product_Service_Category,""));
			engineering1CFList.add(engineering1Category);
			engineering1CFList.add(engineering1Code);
		}
		engineering1Maps.put("item_custom_fields",engineering1CFList);
		service1List.add(engineering1Maps);
	}
}
/** Service Details 2 **/
//Service 2
service2CFLists = List();
if(input.Service_Charges_2.count() > 0)
{
	for each  service2 in input.Service_Charges_2
	{
		service2Maps = Map();
		service2CodeMaps = Map();
		service2CategoryMaps = Map();
		service2Maps.put("name",IFNULL(service2.Service.Service_Name,""));
		service2Maps.put("quantity",IFNULL(service2.sc_Quantity1,1));
		service2Maps.put("rate",IFNULL(service2.Monthly_Service_Fee,0));
		service2Maps.put("tax_id",253658000000170015);
		if(service2.Service.Ad_hoc == true)
		{
			service2CodeMaps.put("api_name","cf_product_service_code");
			service2CodeMaps.put("value",service2.Service.Product_Code_Services);
			service2CategoryMaps.put("api_name","cf_product_services_category");
			service2CategoryMaps.put("value",service2.Service.Product_Service_Category);
			service2CFLists.add(service2CategoryMaps);
			service2CFLists.add(service2CodeMaps);
		}
		service2Maps.put("item_custom_fields",service2CFLists);
		service1List.add(service2Maps);
	}
}
//Set Up 2
setUp2CFLists = List();
if(input.Set_Up_Fees_2.count() > 0)
{
	for each  setUp2 in input.Set_Up_Fees_2
	{
		setUp2Maps = Map();
		setUp2CodeMaps = Map();
		setUp2CategoryMaps = Map();
		setUp2Maps.put("name",IFNULL(setUp2.Set_Up.Set_Up_Name,""));
		setUp2Maps.put("quantity",IFNULL(setUp2.sf_Quantity1,1));
		setUp2Maps.put("rate",IFNULL(setUp2.Fee,0));
		setUp2Maps.put("tax_id",253658000000170015);
		if(setUp2.Set_Up.Ad_hoc == true)
		{
			setUp2CodeMaps.put("api_name","cf_product_service_code");
			setUp2CodeMaps.put("value",setUp2.Set_Up.Product_Code_SetUp);
			setUp2CategoryMaps.put("api_name","cf_product_services_category");
			setUp2CategoryMaps.put("value",setUp2.Set_Up.Product_Service_Category);
			setUp2CFLists.add(setUp2CategoryMaps);
			setUp2CFLists.add(setUp2CodeMaps);
		}
		setUp2Maps.put("item_custom_fields",setUp2CFLists);
		service1List.add(setUp2Maps);
	}
}
//Equipment 2
equipment2CFLists = List();
if(input.Service_Equipment_2.count() > 0)
{
	for each  equipment2 in input.Service_Equipment_2
	{
		equipment2Maps = Map();
		equipment2CodeMaps = Map();
		equipment2CategoryMaps = Map();
		//Mapping
		equipment2Maps.put("name",IFNULL(equipment2.Equipment.Equipment_Name,""));
		equipment2Maps.put("quantity",IFNULL(equipment2.Quantity,1));
		equipment2Maps.put("rate",IFNULL(equipment2.Price,0));
		equipment2Maps.put("tax_id",253658000000170015);
		if(equipment2.Equipment.Ad_Hoc == true)
		{
			equipment2CodeMaps.put("api_name","cf_product_service_code");
			equipment2CodeMaps.put("value",IFNULL(equipment2.Equipment.Equipment_Code,""));
			equipment2CategoryMaps.put("api_name","cf_product_services_category");
			equipment2CategoryMaps.put("value",IFNULL(equipment2.Equipment.Product_Service_Category,""));
			equipment2CFLists.add(equipment2CategoryMaps);
			equipment2CFLists.add(equipment2CodeMaps);
		}
		equipment2Maps.put("item_custom_fields",equipment1CFList);
		service1List.add(equipment2Maps);
	}
}
//Engineering 2
engineering2CFLists = List();
if(input.Service_Engineering_2.count() > 0)
{
	for each  engineering2 in input.Service_Engineering_2
	{
		engineering2Maps = Map();
		engineering2CodeMaps = Map();
		engineering2CategoryMaps = Map();
		//Mapping
		engineering2Maps.put("name",IFNULL(engineering2.Engineering.Service_Name,""));
		engineering2Maps.put("quantity",IFNULL(engineering2.Hours,1));
		engineering2Maps.put("rate",IFNULL(engineering2.Rate,0));
		engineering2Maps.put("tax_id",253658000000170015);
		if(engineering1.Engineering.Ad_hoc == true)
		{
			engineering2CodeMaps.put("api_name","cf_product_service_code");
			engineering2CodeMaps.put("value",IFNULL(engineering2.Engineering.Product_Code_Engineering,""));
			engineering2CategoryMaps.put("api_name","cf_product_services_category");
			engineering2CategoryMaps.put("value",IFNULL(engineering2.Engineering.Product_Service_Category,""));
			engineering2CFLists.add(engineering2CodeMaps);
			engineering2CFLists.add(engineering2CodeMaps);
		}
		engineering2Maps.put("item_custom_fields",engineering2CFLists);
		service1List.add(engineering2Maps);
	}
}
/** Service Details 3 **/
//Service Charge 3
service3CFLists = List();
if(input.Service_Charges_3.count() > 0)
{
	for each  service3 in input.Service_Charges_3
	{
		service3Maps = Map();
		service3CodeMaps = Map();
		service3CategoryMaps = Map();
		//Mapping
		service3Maps.put("name",IFNULL(service3.Service.Service_Name,""));
		service3Maps.put("quantity",IFNULL(service3.sc_Quantity2,1));
		service3Maps.put("rate",IFNULL(service3.Monthly_Service_Fee,0));
		service3Maps.put("tax_id",253658000000170015);
		if(service3.Service.Ad_hoc == true)
		{
			service3CodeMaps.put("api_name","cf_product_service_code");
			service3CodeMaps.put("value",service3.Service.Product_Code_Services);
			service3CategoryMaps.put("api_name","cf_product_services_category");
			service3CategoryMaps.put("value",service3.Service.Product_Service_Category);
			service3CFLists.add(service3CategoryMaps);
			service3CFLists.add(service3CodeMaps);
		}
		service3Maps.put("item_custom_fields",service3CFLists);
		service1List.add(service3Maps);
	}
}
//Set Up 3
setUp3CFLists = List();
if(input.Set_Up_Fees_3.count() > 0)
{
	for each  setUp3 in input.Set_Up_Fees_3
	{
		setUp3Maps = Map();
		setUp3CodeMaps = Map();
		setUp3CategoryMaps = Map();
		//Mapping
		setUp3Maps.put("name",IFNULL(setUp3.Set_Up.Set_Up_Name,""));
		setUp3Maps.put("quantity",IFNULL(setUp3.sf_Quantity2,1));
		setUp3Maps.put("rate",IFNULL(setUp3.Fee,0));
		setUp3Maps.put("tax_id",253658000000170015);
		if(setUp3.Set_Up.Ad_hoc == true)
		{
			setUp3CodeMaps.put("api_name","cf_product_service_code");
			setUp3CodeMaps.put("value",setUp3.Set_Up.Product_Code_SetUp);
			setUp3CategoryMaps.put("api_name","cf_product_services_category");
			setUp3CategoryMaps.put("value",setUp3.Set_Up.Product_Service_Category);
			setUp3CFLists.add(setUp3CategoryMaps);
			setUp3CFLists.add(setUp3CodeMaps);
		}
		setUp3Maps.put("item_custom_fields",setUp3CFLists);
		service1List.add(setUp3Maps);
	}
}
//Equipment 3
equipment3CFLists = List();
if(input.Service_Equipment_3.count() > 0)
{
	for each  equipment3 in input.Service_Equipment_3
	{
		equipment3Maps = Map();
		equipment3CodeMaps = Map();
		equipment3CategoryMaps = Map();
		//Mapping
		equipment3Maps.put("name",IFNULL(equipment3.Equipment.Equipment_Name,""));
		equipment3Maps.put("quantity",IFNULL(equipment3.Quantity,1));
		equipment3Maps.put("rate",IFNULL(equipment3.Price,0));
		equipment3Maps.put("tax_id",253658000000170015);
		if(equipment3.Equipment.Ad_Hoc == true)
		{
			equipment3CodeMaps.put("api_name","cf_product_service_code");
			equipment3CodeMaps.put("value",IFNULL(equipment3.Equipment.Equipment_Code,""));
			equipment3CategoryMaps.put("api_name","cf_product_services_category");
			equipment3CategoryMaps.put("value",IFNULL(equipment3.Equipment.Product_Service_Category,""));
			equipment3CFLists.add(equipment3CategoryMaps);
			equipment3CFLists.add(equipment3CodeMaps);
		}
		equipment3Maps.put("item_custom_fields",equipment3CFLists);
		service1List.add(equipment3Maps);
	}
}
//Engineer 3
engineering3CFLists = List();
if(input.Service_Engineering_3.count() > 0)
{
	for each  engineering3 in input.Service_Engineering_3
	{
		engineering3Maps = Map();
		engineering3CodeMaps = Map();
		engineering3CategoryMaps = Map();
		//Mapping
		engineering3Maps.put("name",IFNULL(engineering3.Engineering.Service_Name,""));
		engineering3Maps.put("quantity",IFNULL(engineering3.Hours,1));
		engineering3Maps.put("rate",IFNULL(engineering3.Rate,0));
		engineering3Maps.put("tax_id",253658000000170015);
		if(engineering3.Engineering.Ad_hoc == true)
		{
			engineering3CodeMaps.put("api_name","cf_product_service_code");
			engineering3CodeMaps.put("value",IFNULL(engineering3.Engineering.Product_Code_Engineering,""));
			engineering3CategoryMaps.put("api_name","cf_product_services_category");
			engineering3CategoryMaps.put("value",IFNULL(engineering3.Engineering.Product_Service_Category,""));
			engineering3CFLists.add(engineering3CodeMaps);
			engineering3CFLists.add(engineering3CategoryMaps);
		}
		engineering3Maps.put("item_custom_fields",engineering3CFLists);
		service1List.add(engineering3Maps);
	}
}
/** Service Details 4 **/
//
//Service Charge 4
service4CFLists = List();
if(input.Service_Charges_4.count() > 0)
{
	for each  service4 in input.Service_Charges_4
	{
		service4Maps = Map();
		service4CodeMaps = Map();
		service4CategoryMaps = Map();
		service4Maps.put("name",IFNULL(service4.Service.Service_Name,""));
		service4Maps.put("quantity",IFNULL(service4.sc_Quantity3,1));
		service4Maps.put("rate",IFNULL(service4.Monthly_Service_Fee,0));
		service4Maps.put("tax_id",253658000000170015);
		if(service4.Service.Ad_hoc == true)
		{
			service4CodeMaps.put("api_name","cf_product_service_code");
			service4CodeMaps.put("value",service4.Service.Product_Code_Services);
			service4CategoryMaps.put("api_name","cf_product_services_category");
			service4CategoryMaps.put("value",service4.Service.Product_Service_Category);
			service4CFLists.add(service4CategoryMaps);
			service4CFLists.add(service4CodeMaps);
		}
		service4Maps.put("item_custom_fields",service4CFLists);
		service1List.add(service4Maps);
	}
}
//Set Up 4
setUp4CFLists = List();
if(input.Set_Up_Fees_4.count() > 0)
{
	for each  setUp4 in input.Set_Up_Fees_4
	{
		setUp4Maps = Map();
		setUp4CodeMaps = Map();
		setUp4CategoryMaps = Map();
		//Mapping
		setUp4Maps.put("name",IFNULL(setUp4.Set_Up.Set_Up_Name,""));
		setUp4Maps.put("quantity",IFNULL(setUp4.sf_Quantity3,1));
		setUp4Maps.put("rate",IFNULL(setUp4.Fee,0));
		setUp4Maps.put("tax_id",253658000000170015);
		if(setUp1.Set_Up.Ad_hoc == true)
		{
			setUp4CodeMaps.put("api_name","cf_product_service_code");
			setUp4CodeMaps.put("value",setUp4.Set_Up.Product_Code_SetUp);
			setUp4CategoryMaps.put("api_name","cf_product_services_category");
			setUp4CategoryMaps.put("value",setUp4.Set_Up.Product_Service_Category);
			setUp4CFLists.add(setUp4CategoryMaps);
			setUp4CFLists.add(setUp4CodeMaps);
		}
		setUp4Maps.put("item_custom_fields",setUp4CFLists);
		service1List.add(setUp4Maps);
	}
}
//Equipment 4
equipment4CFLists = List();
if(input.Service_Equipment_4.count() > 0)
{
	for each  equipment4 in input.Service_Equipment_4
	{
		equipment4Maps = Map();
		equipment4CodeMaps = Map();
		equipment4CategoryMaps = Map();
		//Mapping
		equipment4Maps.put("name",IFNULL(equipment4.Equipment.Equipment_Name,""));
		equipment4Maps.put("quantity",IFNULL(equipment4.Quantity,1));
		equipment4Maps.put("rate",IFNULL(equipment4.Price,0));
		equipment4Maps.put("tax_id",253658000000170015);
		if(equipment4.Equipment.Ad_Hoc == true)
		{
			equipment4CodeMaps.put("api_name","cf_product_service_code");
			equipment4CodeMaps.put("value",IFNULL(equipment4.Equipment.Equipment_Code,""));
			equipment4CategoryMaps.put("api_name","cf_product_services_category");
			equipment4CategoryMaps.put("value",IFNULL(equipment4.Equipment.Product_Service_Category,""));
			equipment4CFLists.add(equipment4CategoryMaps);
			equipment4CFLists.add(equipment4CodeMaps);
		}
		equipment4Maps.put("item_custom_fields",equipment4CFLists);
		service1List.add(equipment4Maps);
	}
}
// Engineering 4
engineering4CFLists = List();
if(input.Service_Engineering_4.count() > 0)
{
	for each  engineering4 in input.Service_Engineering_4
	{
		engineering4Maps = Map();
		engineering4CodeMaps = Map();
		engineering4CategoryMaps = Map();
		//Mapping
		engineering4Maps.put("name",IFNULL(engineering4.Engineering.Service_Name,""));
		engineering4Maps.put("quantity",IFNULL(engineering4.Hours,1));
		engineering4Maps.put("rate",IFNULL(engineering4.Rate,0));
		engineering4Maps.put("tax_id",253658000000170015);
		if(engineering4.Engineering.Ad_hoc == true)
		{
			engineering4CodeMaps.put("api_name","cf_product_service_code");
			engineering4CodeMaps.put("value",IFNULL(engineering4.Engineering.Product_Code_Engineering,""));
			engineering4CategoryMaps.put("api_name","cf_product_services_category");
			engineering4CategoryMaps.put("value",IFNULL(engineering4.Engineering.Product_Service_Category,""));
			engineering4CFLists.add(engineering4CategoryMaps);
			engineering4CFLists.add(engineering4CodeMaps);
		}
		engineering4Maps.put("item_custom_fields",engineering4CFLists);
		service1List.add(engineering4Maps);
	}
}
//Note Mapping From Service 1 to Service 3 is Checked and All Good
/*Carriage and Shipping Charge*/
creatorMaps.put("shipping_charge",IFNULL(input.Total_Carriage,0));
creatorMaps.put("shipping_charge_tax_id","253658000000170015");
/**ALL Line Item**/
creatorMaps.put("line_items",service1List);
// info creatorMaps;
/* Create Record in Inventory*/
try 
{
	createSo = zoho.inventory.createRecord("salesorders","20081056950",creatorMaps,"inventory_auth1");
	info "Sales Order has been created";
	info "Info: \n" + createSo;
	soMessage = IFNULL(createSo.get("message"),"Sales Order has not been created.");
	if(soMessage.equalsIgnoreCase("Sales Order has been created."))
	{
		input.Sales_Order_Created = true;
	}
	salesOrderId = IFNULL(createSo.get("salesorder").get("salesorder_id"),"");
	quoteRecord = Standard_Quote[ID == input.ID];
	quoteRecord.Inventory_Sales_Order_ID=salesOrderId;
	// 	info creatorMaps;
}
catch (e)
{
	info "Catch Response: " + e;
}
