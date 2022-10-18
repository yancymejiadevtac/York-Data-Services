reurringTotalDiscount = IFNULL(input.Recurring_Disount,0);
nonRecurringTotalDiscount = IFNULL(input.Non_recurring_Discount,0);
if(reurringTotalDiscount > 0 && nonRecurringTotalDiscount == 0)
{
	show Service_Discount_Notes_1;
}
else if(reurringTotalDiscount == 0 && nonRecurringTotalDiscount > 0)
{
	show Service_Discount_Notes_1;
}
else if(reurringTotalDiscount > 0 && nonRecurringTotalDiscount > 0)
{
	show Service_Discount_Notes_1;
}
else
{
	hide Service_Discount_Notes_1;
}
