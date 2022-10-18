reurringTotalDiscount = IFNULL(input.Recurring_service_charges_Discount_2,0);
nonRecurringTotalDiscount = IFNULL(input.Non_recurring_charges_Discount_2,0);
if(reurringTotalDiscount > 0 && nonRecurringTotalDiscount == 0)
{
	show Service_Discount_Notes_2;
}
else if(reurringTotalDiscount == 0 && nonRecurringTotalDiscount > 0)
{
	show Service_Discount_Notes_2;
}
else if(reurringTotalDiscount > 0 && nonRecurringTotalDiscount > 0)
{
	show Service_Discount_Notes_2;
}
else
{
	hide Service_Discount_Notes_2;
}