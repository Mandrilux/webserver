/*
** main.c for  in /home/baptiste/project/webserver
**
** Made by
** Login   <baptiste.heraud@epitech.eu>
**
** Started on  Wed Jul 13 13:56:18 2016
** Last update Sat Jul 16 11:45:11 2016 
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
      sin.sin_addr.s_addr = htonl(INADDR_ANY);
      sin.sin_family = AF_INET;
      sin.sin_port = htons(PORT);
      sock_err = bind(sock, (SOCKADDR*)&sin, recsize);
      if(sock_err != SOCKET_ERROR)
	{
	  sock_err = listen(sock, 5);
	  if(sock_err != SOCKET_ERROR)
	    {
	      if (init_dir(ROOT) == -1)
		exit(printf("Impossible d'acceder au fichier web"));
	      printf("Patientez pendant que le client se connecte sur le port %d...\n", PORT);
	      while (1)
		{
		  csock = accept(sock, (SOCKADDR*)&csin, &crecsize);
		  printf("Un client se connecte avec la socket %d de %s:%d\n", csock, inet_ntoa(csin.sin_addr), htons(csin.sin_port));
       		  read_weft(csock, inet_ntoa(csin.sin_addr));
		  /* printf("Fermeture de la socket client\n"); */
		  close(csock);
		}
	    }
	  else
	    perror("listen");
	}
      else
	perror("bind");
      close(sock);
    }
  else
    perror("socket");
  return EXIT_SUCCESS;
}
