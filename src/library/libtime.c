#include "libtime.h"

int ric_new_time(LIBRARY_PARAMS()) {
  time_t now;

  /* Current time */
  time( &now );

  /* Pushing result */
  PUSH_TIME(now, sp, sc);

  return 0;
}

int ric_time_seconds(LIBRARY_PARAMS()) {
  time_t arg1;
  stackval_t stv;
  int32_t result = 0;

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TIMETYPE:
    arg1 = stv.time;
    break;
    default: {
      fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
        LIBRARY_FUNC_NAME());
      return 1;
    }
    break;
  }
  result = (int32_t) arg1;
  PUSH_INT(result, sp, sc);
  return 0;
}

int ric_time_minutes(LIBRARY_PARAMS()) {
  time_t arg1;
  stackval_t stv;
  int32_t result = 0;

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TIMETYPE:
    arg1 = stv.time;
    break;
    default: {
      fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
        LIBRARY_FUNC_NAME());
      return 1;
    }
    break;
  }
  result = (int32_t) arg1 / 60;
  PUSH_INT(result, sp, sc);
  return 0;
}

int ric_time_hours(LIBRARY_PARAMS()) {
  time_t arg1;
  stackval_t stv;
  int32_t result = 0;

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TIMETYPE:
    arg1 = stv.time;
    break;
    default: {
      fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
        LIBRARY_FUNC_NAME());
      return 1;
    }
    break;
  }
  result = arg1 / (60*60);
  PUSH_INT(result, sp, sc);
  return 0;
}

int ric_time_days(LIBRARY_PARAMS()) {
  time_t arg1;
  stackval_t stv;
  int32_t result = 0;

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TIMETYPE:
    arg1 = stv.time;
    break;
    default: {
      fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
        LIBRARY_FUNC_NAME());
      return 1;
    }
    break;
  }
  result = (int32_t) arg1 / (60*60*24);
  PUSH_INT(result, sp, sc);
  return 0;
}

int ric_time_weeks(LIBRARY_PARAMS()) {
  time_t arg1;
  stackval_t stv;
  int32_t result = 0;

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TIMETYPE:
    arg1 = stv.time;
    break;
    default: {
      fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
        LIBRARY_FUNC_NAME());
      return 1;
    }
    break;
  }
  result = (int32_t) arg1 / (60*60*24*7);
  PUSH_INT(result, sp, sc);
  return 0;
}

int ric_time_months(LIBRARY_PARAMS()) {
  time_t arg1;
  stackval_t stv;
  int32_t result = 0;
  struct tm *info;

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TIMETYPE:
    arg1 = stv.time;
    break;
    default: {
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

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TIMETYPE:
    arg1 = stv.time;
    break;
    default: {
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

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TIMETYPE:
    arg1 = stv.time;
    break;
    default: {
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

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TIMETYPE:
    arg1 = stv.time;
    break;
    default: {
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

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TIMETYPE:
    arg1 = stv.time;
    break;
    default: {
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

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TIMETYPE:
    arg1 = stv.time;
    break;
    default: {
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

int ric_time_week(LIBRARY_PARAMS()) {
  time_t arg1;
  stackval_t stv;
  int32_t result = 0;
  struct tm *info;
  char textBuf[5];

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TIMETYPE:
    arg1 = stv.time;
    break;
    default: {
      fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
        LIBRARY_FUNC_NAME());
      return 1;
    }
    break;
  }

  info = localtime(&arg1);

  // Gonna let strftime do this for me, %V is for the ISO 8601 week number.
  memset(textBuf, 0, sizeof(textBuf));
  strftime(textBuf, sizeof(textBuf), "%V", info);
  result = atoi(textBuf);

  PUSH_INT(result, sp, sc);
  return 0;
}

int ric_time_month(LIBRARY_PARAMS()) {
  time_t arg1;
  stackval_t stv;
  int32_t result = 0;
  struct tm *info;

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TIMETYPE:
    arg1 = stv.time;
    break;
    default: {
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

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TIMETYPE:
    arg1 = stv.time;
    break;
    default: {
      fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
        LIBRARY_FUNC_NAME());
      return 1;
    }
    break;
  }

  info = localtime(&arg1);

  result = (int32_t) info->tm_year + 1900;

  PUSH_INT(result, sp, sc);
  return 0;
}



