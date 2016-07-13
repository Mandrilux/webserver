
#include "data.h"

int	main()
{
  int erreur = 0;
  SOCKADDR_IN sin;
  SOCKET sock;
  socklen_t recsize = sizeof(sin);
  SOCKADDR_IN csin;
  SOCKET csock;
  socklen_t crecsize = sizeof(csin);
  int sock_err;
  /* char	buffer[32]; */

  if(!erreur)
    {
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
		  csock = accept(sock, (SOCKADDR*)&csin, &crecsize);
		  printf("Un client se connecte avec la socket %d de %s:%d\n", csock, inet_ntoa(csin.sin_addr), htons(csin.sin_port));
		  /* if(recv(sock, buffer, 32, 0) != SOCKET_ERROR) */
		  /*   printf("Recu : %s\n", buffer); */
		}
	      else
		perror("listen");
	    }
	  else
	    perror("bind");
	  printf("Fermeture de la socket client\n");
	  close(csock);
	  printf("Fermeture de la socket serveur\n");
	  close(sock);
	  printf("Fermeture du serveur terminée\n");
	}
      else
	perror("socket");
    }
  return (EXIT_SUCCESS);
}
