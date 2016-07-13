
#include "data.h"

int	main()
{
  /* int erreur = 0; */
  SOCKADDR_IN sin;
  SOCKET sock;
  socklen_t recsize = sizeof(sin);
  SOCKADDR_IN csin;
  SOCKET csock;
  socklen_t crecsize = sizeof(csin);
  int sock_err;


  char response[] = "HTTP/1.1 200 OK\r\n"
    "Content-Type: text/html; charset=UTF-8\r\n\r\n"
    "<!DOCTYPE html><html><head><title>Bye-bye baby bye-bye</title>"
    "<style>body { background-color: #111 }"
    "h1 { font-size:4cm; text-align: center; color: black;"
    " text-shadow: 0 0 2mm red}</style></head>"
    "<body><h1>Goodbye, world!</h1></body></html>\r\n";


  /* if(!erreur) */
  /*   { */
      sock = socket(AF_INET, SOCK_STREAM, 0);
      if(sock != INVALID_SOCKET)
	{
	  printf("La socket %d est maintenant ouverte en mode TCP/IP\n", sock);
	  sin.sin_addr.s_addr = htonl(INADDR_ANY);
	  sin.sin_family = AF_INET;
	  sin.sin_port = htons(PORT);
	  sock_err = bind(sock, (SOCKADDR*)&sin, recsize);
	  if(sock_err != SOCKET_ERROR)
	    {
	      sock_err = listen(sock, 5);
	      printf("Listage du port %d...\n", PORT);
	      if(sock_err != SOCKET_ERROR)
		{
		  printf("Patientez pendant que le client se connecte sur le port %d...\n", PORT);
		  while (1)
		    {
		      usleep(.100);
		      csock = accept(sock, (SOCKADDR*)&csin, &crecsize);
		      printf("Un client se connecte avec la socket %d de %s:%d\n", csock, inet_ntoa(csin.sin_addr), htons(csin.sin_port));
		      write(csock, response, sizeof(response) - 1);
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
    /* } */
  return (EXIT_SUCCESS);
}
