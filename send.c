/*
** send.c for  in /home/baptiste/project/webserver
**
** Made by
** Login   <baptiste.heraud@epitech.eu>
**
** Started on  Thu Jul 14 11:24:09 2016
** Last update Thu Jul 14 11:37:10 2016 
*/

#include "data.h"

int     send_weft_200(SOCKET csock, char *ip, t_weft data)
{
      char response[] = "HTTP/1.1 200 OK\r\n"
	          "Content-Type: text/html; charset=UTF-8\r\n\r\n"
	          "<!DOCTYPE html><html><head><title>Bye-bye baby bye-bye</title>"
	          "<style>body { background-color: #112 }"
	          "h1 { font-size:4cm; text-align: center; color: black;"
	          " text-shadow: 0 0 2mm red}</style></head>"
	"<body><h1>Goodbye, world!</h1></body></html>\r\n";
      write(csock, response, sizeof(response) - 1);
      log_access_file(ip, data.type, data.user_agent, LOG_ACCESS);
      return (1);
}

int     send_weft_404(SOCKET csock, char *ip, char *path)
{
      char response[] = "HTTP/1.1 404 OK\r\n"
	          "Content-Type: text/html; charset=UTF-8\r\n\r\n"
	          "<!DOCTYPE html><html><head><title>404 NO FOUND</title>"
	          "<style>body { background-color: white }"
	          "h1 { font-size:4cm; text-align: center; color: black;"
	          " text-shadow: 0 0 2mm red}</style></head>"
	"<body><h1>Goodbye, world!</h1></body></html>\r\n";
      write(csock, response, sizeof(response) - 1);
      log_error_file("ERROR", ip, path, LOG_ERROR);
      return (1);
}
