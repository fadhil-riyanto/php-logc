/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: b4649106dd26a0a7d574ab6373a4732dcfe9c273 */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_test1, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_test2, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, str, IS_STRING, 0, "\"\"")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_test_f, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, str, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_test2arg, 0, 0, IS_NULL, 1)
	ZEND_ARG_VARIADIC_TYPE_INFO(0, int1, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_FUNCTION(test1);
ZEND_FUNCTION(test2);
ZEND_FUNCTION(test_f);
ZEND_FUNCTION(test2arg);

static const zend_function_entry ext_functions[] = {
	ZEND_FE(test1, arginfo_test1)
	ZEND_FE(test2, arginfo_test2)
	ZEND_FE(test_f, arginfo_test_f)
	ZEND_FE(test2arg, arginfo_test2arg)
	ZEND_FE_END
};
