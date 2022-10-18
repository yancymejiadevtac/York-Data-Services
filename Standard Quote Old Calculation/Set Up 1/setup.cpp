row.Fee=IFNULL(row.Set_Up.Set_Up_Cost,0.00);
/*
* Calcualtions For Total in the row
*
*/
if(input.sc0 = true && row.sf_Quantity0 != null && row.Fee != null)
{
	row.sf_Total0=row.Fee * row.sf_Quantity0;
}
else if(input.sc0 = true && row.sf_Quantity0 == null || row.Fee == null)
{
	row.sf_Total0=0;
}
//
/********************************************************
*		    			NOTE TO YANCY/Dev				*
*		 When updaing all the total calculation			*
*		make sure to check the variables of the			* 	
*		following:										*
*		1.input.sc										*
*		2.input.sf_Total								*
*		3.input.sc_Total								*
*********************************************************/
//
//
//GLOBAL VARIABLES
vat = Global_Settings[KEY == "DEFAULT_VAT"].VALUE.toDecimal();
vat = IFNULL(vat,0.00) / 100;
//
sd_totals1 = 0.00;
monthly_fee1 = 0.00;
upfront_fee1 = 0.00;
if(input.sc0 == true)
{
	for each  rec_sc_1 in input.Service_Charges
	{
		val_row = IFNULL(rec_sc_1.sc_Total0,0.00);
		sd_totals1 = sd_totals1 + val_row;
		monthly_fee1 = monthly_fee1 + val_row;
	}
	for each  rec_suf_1 in input.Set_Up_Fees
	{
		val_row = IFNULL(rec_suf_1.sf_Total0,0.00);
		sd_totals1 = sd_totals1 + val_row;
		upfront_fee1 = upfront_fee1 + val_row;
	}
	for each  rec_seq_1 in input.Service_Equipment
	{
		val_price = IFNULL(rec_seq_1.Price,0.00);
		val_qty = IFNULL(rec_seq_1.Quantity,1);
		val_row = val_price * val_qty;
		sd_totals1 = sd_totals1 + val_row;
		upfront_fee1 = upfront_fee1 + val_row;
	}
	for each  rec_sen_1 in input.Service_Engineering
	{
		val_rate = IFNULL(rec_sen_1.Rate,0.00);
		val_hrs = IFNULL(rec_sen_1.Hours,0.00);
		val_row = val_rate * val_hrs;
		sd_totals1 = sd_totals1 + val_row;
		upfront_fee1 = upfront_fee1 + val_row;
	}
}
else if(input.sc0 == false)
{
	for each  rec_sc_1 in input.Service_Charges
	{
		val_row = IFNULL(rec_sc_1.Monthly_Service_Fee,0.00);
		sd_totals1 = sd_totals1 + val_row;
		monthly_fee1 = monthly_fee1 + val_row;
	}
	for each  rec_suf_1 in input.Set_Up_Fees
	{
		val_row = IFNULL(rec_suf_1.Fee,0.00);
		sd_totals1 = sd_totals1 + val_row;
		upfront_fee1 = upfront_fee1 + val_row;
	}
	for each  rec_seq_1 in input.Service_Equipment
	{
		val_price = IFNULL(rec_seq_1.Price,0.00);
		val_qty = IFNULL(rec_seq_1.Quantity,1);
		val_row = val_price * val_qty;
		sd_totals1 = sd_totals1 + val_row;
		upfront_fee1 = upfront_fee1 + val_row;
	}
	for each  rec_sen_1 in input.Service_Engineering
	{
		val_rate = IFNULL(rec_sen_1.Rate,0.00);
		val_hrs = IFNULL(rec_sen_1.Hours,0.00);
		val_row = val_rate * val_hrs;
		sd_totals1 = sd_totals1 + val_row;
		upfront_fee1 = upfront_fee1 + val_row;
	}
}
upfront_fee1 = IFNULL(input.Carriage,0) + upfront_fee1;
input.Up_Front_Sub_Total = upfront_fee1;
input.Service_Charges_Sub_Total = monthly_fee1;
input.Service_Sub_Total = sd_totals1 + IFNULL(input.Carriage,0);
//Additional Package
/*
*  Second Package
* 
*/
sd_totals2 = 0.00;
monthly_fee2 = 0.00;
upfront_fee2 = 0.00;
//
sd_totals3 = 0.00;
monthly_fee3 = 0.00;
upfront_fee3 = 0.00;
//
sd_totals4 = 0.00;
monthly_fee4 = 0.00;
upfront_fee4 = 0.00;
if(input.Add_another_service == true)
{
	if(input.sc1 == true)
	{
		//This condition is when the Service Category falls on the 4 Category that show the Total in Service and Set Up Fee
		for each  rec_sc_2 in input.Service_Charges_2
		{
			val_row = IFNULL(rec_sc_2.sc_Total1,0.00);
			sd_totals2 = sd_totals2 + val_row;
			monthly_fee2 = monthly_fee2 + val_row;
		}
		for each  rec_suf_2 in input.Set_Up_Fees_2
		{
			val_row = IFNULL(rec_suf_2.sf_Total1,0.00);
			sd_totals2 = sd_totals2 + val_row;
			upfront_fee2 = upfront_fee2 + val_row;
		}
		for each  rec_seq_2 in input.Service_Equipment_2
		{
			val_price = IFNULL(rec_seq_2.Price,0.00);
			val_qty = IFNULL(rec_seq_2.Quantity,1);
			val_row = val_price * val_qty;
			sd_totals2 = sd_totals2 + val_row;
			upfront_fee2 = upfront_fee2 + val_row;
		}
		for each  rec_sen_2 in input.Service_Engineering_2
		{
			val_rate = IFNULL(rec_sen_2.Rate,0.00);
			val_hrs = IFNULL(rec_sen_2.Hours,0.00);
			val_row = val_rate * val_hrs;
			sd_totals2 = sd_totals2 + val_row;
			upfront_fee2 = upfront_fee2 + val_row;
		}
	}
	else if(input.sc1 == false)
	{
		for each  rec_sc_2 in input.Service_Charges_2
		{
			val_row = IFNULL(rec_sc_2.Monthly_Service_Fee,0.00);
			sd_totals2 = sd_totals2 + val_row;
			monthly_fee2 = monthly_fee2 + val_row;
		}
		for each  rec_suf_2 in input.Set_Up_Fees_2
		{
			val_row = IFNULL(rec_suf_2.Fee,0.00);
			sd_totals2 = sd_totals2 + val_row;
			upfront_fee2 = upfront_fee2 + val_row;
		}
		for each  rec_seq_2 in input.Service_Equipment_2
		{
			val_price = IFNULL(rec_seq_2.Price,0.00);
			val_qty = IFNULL(rec_seq_2.Quantity,1);
			val_row = val_price * val_qty;
			sd_totals2 = sd_totals2 + val_row;
			upfront_fee2 = upfront_fee2 + val_row;
		}
		for each  rec_sen_2 in input.Service_Engineering_2
		{
			val_rate = IFNULL(rec_sen_2.Rate,0.00);
			val_hrs = IFNULL(rec_sen_2.Hours,0.00);
			val_row = val_rate * val_hrs;
			sd_totals2 = sd_totals2 + val_row;
			upfront_fee2 = upfront_fee2 + val_row;
		}
	}
	//Service 2
	upfront_fee2 = IFNULL(input.Carriage_2,0) + upfront_fee2;
	input.Up_Front_Sub_Total_2 = upfront_fee2;
	input.Service_Charges_Sub_Total_2 = monthly_fee2;
	input.Service_Sub_Total_2 = sd_totals2 + IFNULL(input.Carriage_2,0);
	/*
	*
	* Third Package
	*
	*/
	if(input.Add_another_service_2 == true)
	{
		if(input.sc2 == true)
		{
			for each  rec_sc_3 in input.Service_Charges_3
			{
				val_row = IFNULL(rec_sc_3.sc_Total2,0.00);
				sd_totals3 = sd_totals3 + val_row;
				monthly_fee3 = monthly_fee3 + val_row;
			}
			for each  rec_suf_3 in input.Set_Up_Fees_3
			{
				val_row = IFNULL(rec_suf_3.sf_Total2,0.00);
				sd_totals3 = sd_totals3 + val_row;
				upfront_fee3 = upfront_fee3 + val_row;
			}
			for each  rec_seq_3 in input.Service_Equipment_3
			{
				val_price = IFNULL(rec_seq_3.Price,0.00);
				val_qty = IFNULL(rec_seq_3.Quantity,1);
				val_row = val_price * val_qty;
				sd_totals3 = sd_totals3 + val_row;
				upfront_fee3 = upfront_fee3 + val_row;
			}
			for each  rec_sen_3 in input.Service_Engineering_3
			{
				val_rate = IFNULL(rec_sen_3.Rate,0.00);
				val_hrs = IFNULL(rec_sen_3.Hours,0.00);
				val_row = val_rate * val_hrs;
				sd_totals3 = sd_totals3 + val_row;
				upfront_fee3 = upfront_fee3 + val_row;
			}
		}
		else if(input.sc2 == false)
		{
			for each  rec_sc_3 in input.Service_Charges_3
			{
				val_row = IFNULL(rec_sc_3.Monthly_Service_Fee,0.00);
				sd_totals3 = sd_totals3 + val_row;
				monthly_fee3 = monthly_fee3 + val_row;
			}
			for each  rec_suf_3 in input.Set_Up_Fees_3
			{
				val_row = IFNULL(rec_suf_3.Fee,0.00);
				sd_totals3 = sd_totals3 + val_row;
				upfront_fee3 = upfront_fee3 + val_row;
			}
			for each  rec_seq_3 in input.Service_Equipment_3
			{
				val_price = IFNULL(rec_seq_3.Price,0.00);
				val_qty = IFNULL(rec_seq_3.Quantity,1);
				val_row = val_price * val_qty;
				sd_totals3 = sd_totals3 + val_row;
				upfront_fee3 = upfront_fee3 + val_row;
			}
			for each  rec_sen_3 in input.Service_Engineering_3
			{
				val_rate = IFNULL(rec_sen_3.Rate,0.00);
				val_hrs = IFNULL(rec_sen_3.Hours,0.00);
				val_row = val_rate * val_hrs;
				sd_totals3 = sd_totals3 + val_row;
				upfront_fee3 = upfront_fee3 + val_row;
			}
		}
		//Service 3
		upfront_fee3 = IFNULL(input.Carriage_3,0) + upfront_fee3;
		input.Up_Front_Sub_Total_3 = upfront_fee3;
		input.Service_Charges_Sub_Total_3 = monthly_fee3;
		input.Service_Sub_Total_3 = sd_totals3 + IFNULL(input.Carriage_3,0);
		/*
		*
		* Last Package
		*
		*/
		if(input.Add_another_service_3)
		{
			if(input.sc3 == true)
			{
				for each  rec_sc_4 in input.Service_Charges_4
				{
					val_row = IFNULL(rec_sc_4.sc_Total3,0.00);
					sd_totals4 = sd_totals4 + val_row;
					monthly_fee4 = monthly_fee4 + val_row;
				}
				for each  rec_suf_4 in input.Set_Up_Fees_4
				{
					val_row = IFNULL(rec_suf_4.sf_Total3,0.00);
					sd_totals4 = sd_totals4 + val_row;
					upfront_fee4 = upfront_fee4 + val_row;
				}
				for each  rec_seq_4 in input.Service_Equipment_4
				{
					val_price = IFNULL(rec_seq_4.Price,0.00);
					val_qty = IFNULL(rec_seq_4.Quantity,1);
					val_row = val_price * val_qty;
					sd_totals4 = sd_totals4 + val_row;
					upfront_fee4 = upfront_fee4 + val_row;
				}
				for each  rec_sen_4 in input.Service_Engineering_4
				{
					val_rate = IFNULL(rec_sen_4.Rate,0.00);
					val_hrs = IFNULL(rec_sen_4.Hours,0.00);
					val_row = val_rate * val_hrs;
					sd_totals4 = sd_totals4 + val_row;
					upfront_fee4 = upfront_fee4 + val_row;
				}
			}
			else if(input.sc3 == false)
			{
				for each  rec_sc_4 in input.Service_Charges_4
				{
					val_row = IFNULL(rec_sc_4.Monthly_Service_Fee,0.00);
					sd_totals4 = sd_totals4 + val_row;
					monthly_fee4 = monthly_fee4 + val_row;
				}
				for each  rec_suf_4 in input.Set_Up_Fees_4
				{
					val_row = IFNULL(rec_suf_4.Fee,0.00);
					sd_totals4 = sd_totals4 + val_row;
					upfront_fee4 = upfront_fee4 + val_row;
				}
				for each  rec_seq_4 in input.Service_Equipment_4
				{
					val_price = IFNULL(rec_seq_4.Price,0.00);
					val_qty = IFNULL(rec_seq_4.Quantity,1);
					val_row = val_price * val_qty;
					sd_totals4 = sd_totals4 + val_row;
					upfront_fee4 = upfront_fee4 + val_row;
				}
				for each  rec_sen_4 in input.Service_Engineering_4
				{
					val_rate = IFNULL(rec_sen_4.Rate,0.00);
					val_hrs = IFNULL(rec_sen_4.Hours,0.00);
					val_row = val_rate * val_hrs;
					sd_totals4 = sd_totals4 + val_row;
					upfront_fee4 = upfront_fee4 + val_row;
				}
			}
			//Service 4
			upfront_fee4 = IFNULL(input.Carriage_4,0) + upfront_fee4;
			input.Up_Front_Sub_Total_4 = upfront_fee4;
			input.Service_Charges_Sub_Total_4 = monthly_fee4;
			input.Service_Sub_Total_4 = sd_totals4 + IFNULL(input.Carriage_4,0);
		}
	}
}
//
//OVERALL TOTALS
tot_upfront = upfront_fee1 + upfront_fee2 + upfront_fee3 + upfront_fee4;
upfront_dsc_tot = 0.00;
if(input.Upfront_Discount_Type == "Fixed")
{
	upfront_dsc_tot = IFNULL(input.Upfront_Discount,0.00);
}
else if(input.Upfront_Discount_Type == "Percentage")
{
	dsc_rate = IFNULL(input.Upfront_Discount,0.00) / 100;
	upfront_dsc_tot = tot_upfront * dsc_rate;
}
else
{
	upfront_dsc_tot = null;
}
input.Upfront_Fee = tot_upfront;
tot_upfront = tot_upfront - IFNULL(upfront_dsc_tot,0.00);
upfront_vat = tot_upfront * vat;
grand_tot_upfront = tot_upfront + upfront_vat;
//
tot_monthly = monthly_fee1 + monthly_fee2 + monthly_fee3 + monthly_fee4;
monthly_dsc_tot = 0.00;
if(input.Monthly_Discount_Type == "Fixed")
{
	monthly_dsc_tot = IFNULL(input.Monthly_Discount,0.00);
}
else if(input.Monthly_Discount_Type == "Percentage")
{
	dsc_rate = IFNULL(input.Monthly_Discount,0.00) / 100;
	monthly_dsc_tot = tot_monthly * dsc_rate;
}
else
{
	monthly_dsc_tot = null;
}
input.Monthly_Service_Charges = tot_monthly;
tot_monthly = tot_monthly - IFNULL(monthly_dsc_tot,0.00);
monthly_vat = tot_monthly * vat;
grand_tot_monthly = tot_monthly + monthly_vat;
//
input.Upfront_Discount_Total = upfront_dsc_tot;
input.Monthly_Discount_Total = monthly_dsc_tot;
input.Total_Upfront_VAT = upfront_vat;
input.Total_Monthly_VAT = monthly_vat;
input.Total_Upfront_Fee = grand_tot_upfront;
input.Total_Monthly_Service_Charges = grand_tot_monthly;
