
/*Local Variable*/
creatorMaps = Map();
itemLists = List();
/*Custom Fields*/
customFields = salesorder.get("custom_fields");
for each  customValue in customFields
{
	if(customValue.get("api_name").contains("cf_quote_id"))
	{
		quoteID = customValue.get("value");
	}
	if(customValue.get("api_name").contains("cf_quote_reference_code"))
	{
		quoteReferenceCode = customValue.get("value");
	}
}
/* Field Mapping */
creatorMaps.put("Standard_Quote_ID",quoteID.toLong());
creatorMaps.put("Sales_Order_Number",salesorder.get("salesorder_number"));
creatorMaps.put("Quote_Reference_Code",quoteReferenceCode);
creatorMaps.put("Sales_Person",salesorder.get("salesperson_name"));
creatorMaps.put("Delivery_Method",salesorder.get("delivery_method"));
creatorMaps.put("Sales_Order_Date",salesorder.get("date").toString("dd-MMM-yyyy"));
if(salesorder.get("shipment_date") != "")
{
	creatorMaps.put("Exptected_Shipment_Date",salesorder.get("shipment_date").toString("dd-MMM-yyyy"));
}
creatorMaps.put("Reference",salesorder.get("reference_number"));
creatorMaps.put("Discount",salesorder.get("discount_amount"));
creatorMaps.put("Sub_Total",salesorder.get("sub_total"));
creatorMaps.put("Shipping_Charges",salesorder.get("shipping_charge"));
creatorMaps.put("Total_Amount",salesorder.get("total"));
/* Line Items*/
soLineItems = salesorder.get("line_items");
for each  soItemsData in soLineItems
{
	itemMaps = Map();
	itemMaps.put("Product_Service_Items",soItemsData.get("name"));
	//Get Custom Fields Value
	for each  cfItems in soItemsData.get("item_custom_fields")
	{
		//Check if product code
		if(cfItems.get("api_name") == "cf_product_service_code")
		{
			itemMaps.put("Product_Service_Code",cfItems.get("value"));
		}
		if(cfItems.get("api_name") == "cf_product_services_category")
		{
			itemMaps.put("Product_Services_Category",cfItems.get("value"));
		}
	}
	itemMaps.put("Quantity",soItemsData.get("quantity"));
	itemMaps.put("Rate",soItemsData.get("rate"));
	vat = soItemsData.get("tax_name") + " " + soItemsData.get("tax_percentage") + "%";
	itemMaps.put("Vat",vat);
	itemMaps.put("Amount",soItemsData.get("item_sub_total"));
	itemLists.add(itemMaps);
}
creatorMaps.put("Line_Items",itemLists);
creatorMaps.put("Inventory_Sales_Order_ID",salesorder.get("salesorder_id"));
creatorMaps.put("Discount", IFNULL(salesorder.get("discount"),0));

/* Push To Creator*/
try 
{
	for each  fetchID in salesorder.get("custom_fields")
	{
		if(fetchID.get("api_name") == "cf_creator_sales_order_id")
		{
			updateID = fetchID.get("value");
		}
	}
	info "Creator ID: " + updateID;
	updateRecord = zoho.creator.updateRecord("yds2019","quote-manager","Sales_Order_Report",updateID.toLong(),creatorMaps,Map(),"creator_auth");
	info "Success: " + updateRecord;
}
catch (e)
{
	info "Error: \n" + e;
}
