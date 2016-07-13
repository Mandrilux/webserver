/*
** main.c for  in /home/baptiste/project/webserver
**
** Made by
** Login   <baptiste.heraud@epitech.eu>
**
** Started on  Wed Jul 13 13:56:18 2016
** Last update Wed Jul 13 16:51:20 2016 
*/

#include "data.h"

int	main()
{
  SOCKADDR_IN sin;
  SOCKET sock;
  socklen_t recsize = sizeof(sin);
  SOCKADDR_IN csin;
  SOCKET csock;
  socklen_t crecsize = sizeof(csin);
  int sock_err;

  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) != INVALID_SOCKET)
    {
      printf("La socket %d est maintenant ouverte en mode TCP/IP\n", sock);
      sin.sin_addr.s_addr = htonl(INADDR_ANY);
      sin.sin_family = AF_INET;
      sin.sin_port = htons(PORT);
      sock_err = bind(sock, (SOCKADDR*)&sin, recsize);
      if(sock_err != SOCKET_ERROR)
	{
	  sock_err = listen(sock, 5);
	  if(sock_err != SOCKET_ERROR)
	    {
	      printf("Patientez pendant que le client se connecte sur le port %d...\n", PORT);
	      while (1)
		{
		  csock = accept(sock, (SOCKADDR*)&csin, &crecsize);
		  printf("Un client se connecte avec la socket %d de %s:%d\n", csock, inet_ntoa(csin.sin_addr), htons(csin.sin_port));
       		  read_weft(csock, inet_ntoa(csin.sin_addr));
		  send_weft(csock);
		  usleep(.200);
		  printf("Fermeture de la socket client\n");
		  close(csock);
		}
	    }
	  else
	    perror("listen");
	}
      else
	perror("bind");
      printf("Fermeture de la socket serveur\n");
      close(sock);
      printf("Fermeture du serveur terminée\n");
    }
  else
    perror("socket");
  return (EXIT_SUCCESS);
}

int	read_weft(SOCKET csock, char *ip)
{
  char	buff[1024] = {0};
  int	flag = 0;
  char	**line = NULL;
  char	**path = NULL;
  char	*tmp = NULL;

  if ((flag = read(csock, buff, 1023)) == -1)
    return (-1);
  if ((tmp = epur_str(buff)) == NULL)
    exit (printf("ERROR MEMORY\n"));
  if ((line = strtowordtab(tmp, '\n')) == NULL)
    return (printf("ERROR MEMORY\n"));
  if (line[0] != NULL)
    {
      if ((path = strtowordtab(line[0], ' ')) == NULL)
	return (printf("ERROR MEMORY\n"));
      if (strcmp(path[1], "/") == 0)
	printf("ok\n");
      else
	{
	  printf("ERREUR\n");
	  log_error_file("ERROR", ip, path[1], LOG_ERROR);
	}
    }
  free(tmp);
  free_double_char(path);
  free_double_char(line);
  return (1);
}

int	send_weft(SOCKET csock)
{
  char response[] = "HTTP/1.1 200 OK\r\n"
    "Content-Type: text/html; charset=UTF-8\r\n\r\n"
    "<!DOCTYPE html><html><head><title>Bye-bye baby bye-bye</title>"
    "<style>body { background-color: #112 }"
    "h1 { font-size:4cm; text-align: center; color: black;"
    " text-shadow: 0 0 2mm red}</style></head>"
    "<body><h1>Goodbye, world!</h1></body></html>\r\n";
  write(csock, response, sizeof(response) - 1);
  return (1);
}
