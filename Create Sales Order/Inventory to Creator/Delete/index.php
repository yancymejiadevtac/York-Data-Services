
try 
{
	for each  fetchID in salesorder.get("custom_fields")
	{
		if(fetchID.get("api_name") == "cf_creator_sales_order_id")
		{
			updateID = fetchID.get("value");
		}
	}
	response = invokeurl
	[
		url :"https://creator.zoho.eu/api/v2/yds2019/quote-manager/report/Sales_Order_Report/" + updateID
		type :DELETE
		connection:"creator_auth1"
	];
	info "Success: " + response;
}
catch (e)
{
	info "ERROR: " + e;
}
