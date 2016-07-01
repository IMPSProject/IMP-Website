#include <kore/kore.h>
#include <kore/http.h>

int	page(struct http_request *);
int page(struct http_request *req){
	char hello[] = "<!DOCTYPE html>"
			"<html>"
				"<head>"
						
				"</head>"
				"<body>"
					"IMPS"
				"</body>"
			"</html>";
	http_response(req, 200, hello, sizeof(hello)-1);
	return (KORE_RESULT_OK);
}
