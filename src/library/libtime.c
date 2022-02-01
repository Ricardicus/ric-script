#include "libtime.h"

int ric_new_time(LIBRARY_PARAMS()) {
  time_t now;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  /* Current time */
  time(&now);

  /* Pushing result */
  PUSH_TIME(now, sp, sc);

  return 0;
}

int ric_time_seconds(LIBRARY_PARAMS()) {
  time_t arg1;
  stackval_t stv;
  int32_t result = 0;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TIMETYPE:
      arg1 = stv.time;
      break;
    default:
      {
        fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
                LIBRARY_FUNC_NAME());
        return 1;
      }
      break;
  }
  result = (int32_t)arg1;
  PUSH_INT(result, sp, sc);
  return 0;
}

int ric_time_minutes(LIBRARY_PARAMS()) {
  time_t arg1;
  stackval_t stv;
  int32_t result = 0;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TIMETYPE:
      arg1 = stv.time;
      break;
    default:
      {
        fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
                LIBRARY_FUNC_NAME());
        return 1;
      }
      break;
  }
  result = (int32_t)arg1 / 60;
  PUSH_INT(result, sp, sc);
  return 0;
}

int ric_time_hours(LIBRARY_PARAMS()) {
  time_t arg1;
  stackval_t stv;
  int32_t result = 0;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TIMETYPE:
      arg1 = stv.time;
      break;
    default:
      {
        fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
                LIBRARY_FUNC_NAME());
        return 1;
      }
      break;
  }
  result = arg1 / (60 * 60);
  PUSH_INT(result, sp, sc);
  return 0;
}

int ric_time_days(LIBRARY_PARAMS()) {
  time_t arg1;
  stackval_t stv;
  int32_t result = 0;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TIMETYPE:
      arg1 = stv.time;
      break;
    default:
      {
        fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
                LIBRARY_FUNC_NAME());
        return 1;
      }
      break;
  }
  result = (int32_t)arg1 / (60 * 60 * 24);
  PUSH_INT(result, sp, sc);
  return 0;
}

int ric_time_weeks(LIBRARY_PARAMS()) {
  time_t arg1;
  stackval_t stv;
  int32_t result = 0;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TIMETYPE:
      arg1 = stv.time;
      break;
    default:
      {
        fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
                LIBRARY_FUNC_NAME());
        return 1;
      }
      break;
  }
  result = (int32_t)arg1 / (60 * 60 * 24 * 7);
  PUSH_INT(result, sp, sc);
  return 0;
}

int ric_time_months(LIBRARY_PARAMS()) {
  time_t arg1;
  stackval_t stv;
  int32_t result = 0;
  struct tm *info;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TIMETYPE:
      arg1 = stv.time;
      break;
    default:
      {
        fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
                LIBRARY_FUNC_NAME());
        return 1;
      }
      break;
  }

  info = localtime(&arg1);

  result = info->tm_mon + (info->tm_year) * 12;

  PUSH_INT(result, sp, sc);
  return 0;
}

int ric_time_years(LIBRARY_PARAMS()) {
  time_t arg1;
  stackval_t stv;
  int32_t result = 0;
  struct tm *info;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TIMETYPE:
      arg1 = stv.time;
      break;
    default:
      {
        fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
                LIBRARY_FUNC_NAME());
        return 1;
      }
      break;
  }

  info = localtime(&arg1);

  result = info->tm_year;

  PUSH_INT(result, sp, sc);
  return 0;
}

int ric_time_second(LIBRARY_PARAMS()) {
  time_t arg1;
  stackval_t stv;
  int32_t result = 0;
  struct tm *info;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TIMETYPE:
      arg1 = stv.time;
      break;
    default:
      {
        fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
                LIBRARY_FUNC_NAME());
        return 1;
      }
      break;
  }

  info = localtime(&arg1);

  result = info->tm_sec;

  PUSH_INT(result, sp, sc);
  return 0;
}

int ric_time_minute(LIBRARY_PARAMS()) {
  time_t arg1;
  stackval_t stv;
  int32_t result = 0;
  struct tm *info;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TIMETYPE:
      arg1 = stv.time;
      break;
    default:
      {
        fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
                LIBRARY_FUNC_NAME());
        return 1;
      }
      break;
  }

  info = localtime(&arg1);

  result = info->tm_min;

  PUSH_INT(result, sp, sc);
  return 0;
}

int ric_time_hour(LIBRARY_PARAMS()) {
  time_t arg1;
  stackval_t stv;
  int32_t result = 0;
  struct tm *info;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TIMETYPE:
      arg1 = stv.time;
      break;
    default:
      {
        fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
                LIBRARY_FUNC_NAME());
        return 1;
      }
      break;
  }

  info = localtime(&arg1);

  result = info->tm_hour;

  PUSH_INT(result, sp, sc);
  return 0;
}

int ric_time_day(LIBRARY_PARAMS()) {
  time_t arg1;
  stackval_t stv;
  int32_t result = 0;
  struct tm *info;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TIMETYPE:
      arg1 = stv.time;
      break;
    default:
      {
        fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
                LIBRARY_FUNC_NAME());
        return 1;
      }
      break;
  }

  info = localtime(&arg1);

  result = info->tm_mday;

  PUSH_INT(result, sp, sc);
  return 0;
}

/*
 *
 * Instead of relying on strftime for ISO 8601, I found
 * this big brain energy function off the internet:
 * https://stackoverflow.com/questions/42568215/iso-8601-week-number-in-c
 *
 */

static int tm_YearWeek(const struct tm *tmptr, int32_t *week) {
  // work with local copy
  struct tm tm = *tmptr;
  // fully populate the yday and wday fields.
  if (mktime(&tm) == -1) {
    return 1;
  }

  // Find day-of-the-week: 0 to 6.
  // Week starts on Monday per ISO 8601
  // 0 <= DayOfTheWeek <= 6, Monday, Tuesday ... Sunday
  int DayOfTheWeek = (tm.tm_wday + (7 - 1)) % 7;

  // Offset the month day to the Monday of the week.
  tm.tm_mday -= DayOfTheWeek;
  // Offset the month day to the mid-week (Thursday) of the week, 3 days later.
  tm.tm_mday += 3;
  // Re-evaluate tm_year and tm_yday  (local time)
  if (mktime(&tm) == -1) {
    return 1;
  }

  // Convert yday to week of the year, stating with 1.
  *week = tm.tm_yday / 7 + 1;
  return 0;
}

int ric_time_week(LIBRARY_PARAMS()) {
  time_t arg1;
  stackval_t stv;
  int32_t result = 0;
  struct tm *info;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TIMETYPE:
      arg1 = stv.time;
      break;
    default:
      {
        fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
                LIBRARY_FUNC_NAME());
        return 1;
      }
      break;
  }

  info = localtime(&arg1);

  tm_YearWeek(info, &result);

  PUSH_INT(result, sp, sc);
  return 0;
}

int ric_time_month(LIBRARY_PARAMS()) {
  time_t arg1;
  stackval_t stv;
  int32_t result = 0;
  struct tm *info;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TIMETYPE:
      arg1 = stv.time;
      break;
    default:
      {
        fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
                LIBRARY_FUNC_NAME());
        return 1;
      }
      break;
  }

  info = localtime(&arg1);

  result = info->tm_mon + 1;

  PUSH_INT(result, sp, sc);
  return 0;
}

int ric_time_year(LIBRARY_PARAMS()) {
  time_t arg1;
  stackval_t stv;
  int32_t result = 0;
  struct tm *info;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TIMETYPE:
      arg1 = stv.time;
      break;
    default:
      {
        fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
                LIBRARY_FUNC_NAME());
        return 1;
      }
      break;
  }

  info = localtime(&arg1);

  result = (int32_t)info->tm_year + 1900;

  PUSH_INT(result, sp, sc);
  return 0;
}
