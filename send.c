/*
** send.c for  in /home/baptiste/project/webserver
**
** Made by
** Login   <baptiste.heraud@epitech.eu>
**
** Started on  Thu Jul 14 11:24:09 2016
** Last update Fri Jul 15 12:53:13 2016 
*/

#include "data.h"


int	send_page(SOCKET csock, t_weft *data, char *ip)
{
  char	*response = NULL;

  if (data->code_page != NULL)
    response = calloc(75 + strlen(data->code_page) ,sizeof(char));
  else
    response = calloc(75 + 100 ,sizeof(char));
  if (response == NULL)
    return (-1);
  if (data->error == 200)
    sprintf(response,"%s%s%s\r\n","HTTP/1.1 200 OK\r\n","Content-Type: text/html; charset=UTF-8\r\n\r\n", data->code_page);
  else
    {
      sprintf(response, "%s",  "HTTP/1.1 404 Not Found\r\n"
	     "Content-Type: text/html; charset=UTF-8\r\n\r\n"
	     "<!DOCTYPE html><html><head><title>404 NO FOUND</title>"
	     "<style>body { background-color: white }"
	     "h1 { font-size:4cm; text-align: center; color: black;"
	     " text-shadow: 0 0 2mm red}</style></head>"
	     "<body><h1>Not Found</h1><hr><p> V.01 serv_baptiste</body></html>\r\n");
    }
  return (1);
}

/* int     send_weft_200(SOCKET csock, char *ip, t_weft data) */
/* { */
/*       char response[] = "HTTP/1.1 200 OK\r\n" */
/* 	          "Content-Type: text/html; charset=UTF-8\r\n\r\n" */
/* 	          "<!DOCTYPE html><html><head><title>Bye-bye baby bye-bye</title>" */
/* 	          "<style>body { background-color: #112 }" */
/* 	          "h1 { font-size:4cm; text-align: center; color: black;" */
/* 	          " text-shadow: 0 0 2mm red}</style></head>" */
/* 	"<body><h1>Goodbye, world!</h1></body></html>\r\n"; */
/*       write(csock, response, sizeof(response) - 1); */
/*       log_access_file(ip, data.type, data.user_agent, LOG_ACCESS); */
/*       return (1); */
/* } */

/* int     send_weft_404(SOCKET csock, char *ip, char *path) */
/* { */
/*       char response[] = "HTTP/1.1 404 Not Found\r\n" */
/* 	          "Content-Type: text/html; charset=UTF-8\r\n\r\n" */
/* 	          "<!DOCTYPE html><html><head><title>404 NO FOUND</title>" */
/* 	          "<style>body { background-color: white }" */
/* 	          "h1 { font-size:4cm; text-align: center; color: black;" */
/* 	          " text-shadow: 0 0 2mm red}</style></head>" */
/* 	"<body><h1>Not Found</h1><hr><p> V.01 serv_baptiste</body></html>\r\n"; */
/*       write(csock, response, sizeof(response) - 1); */
/*       log_error_file("ERROR", ip, path, LOG_ERROR); */
/*       return (1); */
/* } */
