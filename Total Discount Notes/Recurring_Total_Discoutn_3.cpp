reurringTotalDiscount = IFNULL(input.Recurring_service_charges_Discount_3,0);
nonRecurringTotalDiscount = IFNULL(input.Non_recurring_charges_Discount_3,0);
if(reurringTotalDiscount > 0 && nonRecurringTotalDiscount == 0)
{
	show Service_Discount_Notes_3;
}
else if(reurringTotalDiscount == 0 && nonRecurringTotalDiscount > 0)
{
	show Service_Discount_Notes_3;
}
else if(reurringTotalDiscount > 0 && nonRecurringTotalDiscount > 0)
{
	show Service_Discount_Notes_3;
}
else
{
	hide Service_Discount_Notes_3;
}
