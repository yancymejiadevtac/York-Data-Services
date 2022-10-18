//GLOBAL VARIABLES
vat = Global_Settings[KEY == "DEFAULT_VAT"].VALUE.toDecimal();
vat = IFNULL(vat,0.00) / 100;
//
var_deleted_value = IFNULL(row.sc_Total2,0.00);
var_deleted_discount = IFNULL(row.Total_Discount,0);
if(input.Service_Charges_3.count() > 0)
{
	totalNet = 0;
	totalDiscount = 0;
	for each  serviceData in input.Service_Charges_3
	{
		totalNet = totalNet + IFNULL(serviceData.sc_Total2,0);
		totalDiscount = totalDiscount + IFNULL(serviceData.Total_Discount,0);
	}
	totalNet = totalNet - var_deleted_value;
	totalDiscount = totalDiscount - var_deleted_discount;
	totalVat = totalNet * vat;
	totalRecurring = totalNet - totalDiscount;
	input.Recurring_service_charges_Net_3 = totalNet;
	input.Recurring_service_charges_Discount_3 = totalDiscount;
	input.recurring_Vat_3 = totalVat;
	input.Recurring_service_charges_Total_3 = totalRecurring + totalVat;
}