#ifndef LIBTIME_H
#define LIBTIME_H

#include <time.h>

#include "ast.h"

int ric_new_time(LIBRARY_PARAMS());
int ric_time_seconds(LIBRARY_PARAMS());
int ric_time_minutes(LIBRARY_PARAMS());
int ric_time_hours(LIBRARY_PARAMS());
int ric_time_days(LIBRARY_PARAMS());
int ric_time_weeks(LIBRARY_PARAMS());
int ric_time_months(LIBRARY_PARAMS());
int ric_time_years(LIBRARY_PARAMS());
int ric_time_second(LIBRARY_PARAMS());
int ric_time_minute(LIBRARY_PARAMS());
int ric_time_hour(LIBRARY_PARAMS());
int ric_time_day(LIBRARY_PARAMS());
int ric_time_week(LIBRARY_PARAMS());
int ric_time_month(LIBRARY_PARAMS());
int ric_time_year(LIBRARY_PARAMS());

#endif
