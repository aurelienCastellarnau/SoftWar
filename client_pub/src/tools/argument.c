/*
** argument.c for SoftWar in /home/code/SoftWar/aurelien/src
** 
** Made by CASTELLARNAU Aurelien
** Login   <castel_a@etna-alternance.net>
** 
** Started on  Sat Jul  1 01:39:47 2017 CASTELLARNAU Aurelien
** Last update Sat Jul  1 02:24:24 2017 CASTELLARNAU Aurelien
*/

#include <stdlib.h>
#include "libmy.h"
#include "protocol.h"

void		help()
{
  my_putstr_color("cyan", "\n----- HELP -----\n\n");
  my_putstr_color("cyan", "./demo [-proto] !int[int...5]\n");
}

t_chain		*get_options()
{
  t_chain	*options;
  t_option	*logger;
  t_option	*log_file;
  t_option	*protocol;

  if ((options = create_chain(free_options_in_chain)) == NULL)
    {
      // devlog construit un logger temporaire
      // (avec build_default_logger() >> libmy/logger.c)
      // qui affiche avant l'instanciation du logger static
      // (avec build_logger() >> libmy/logger.c)
      // comme le logger par défaut est réglé en dur sur DEBUG
      // devlog affiche le log systématiquement.
      devlog(__func__, "create chain failed", 1);
      return (NULL);
    }
  if ((protocol = new_option(OPTIONNAL, 1, 5, "-proto", display_notification)) == NULL)
    {
      devlog(__func__, "create option protocol failed", 1); 
      return (NULL);
    }
  if ((logger = new_option(OPTIONNAL, 0, 1, "-v", build_logger)) == NULL)
    {
      devlog(__func__, "create option verbose failed", 1); 
      return (NULL);
    }
  if ((log_file = new_option(OPTIONNAL, 1, 0, "-log", build_logger)) == NULL)
    {
      devlog(__func__, "create option protocol failed", 1); 
      return (NULL);
    }
  if (add_link(&options, protocol))
    {
      devlog(__func__, "add protocol option to chain failed", 1);
      return (NULL);
    }
  if (add_link(&options, logger))
    {
      devlog(__func__, "add protocol option to chain failed", 1);
      return (NULL);
    }
  if (add_link(&options, log_file))
    {
      devlog(__func__, "add protocol option to chain failed", 1);
      return (NULL);
    }
  return (options);
}

int	execute(t_option *option)
{
  char	*opt;

  opt = option->name;
  if (!my_strcmp(opt, "-h"))
    (*(void (*)(void))option->action)();
  if (!my_strcmp(opt, "-v") || !my_strcmp(opt, "-log"))
    (*(void (*)(char*, t_chain*))option->action)(opt, option->parameters);
  if (!my_strcmp(opt, "-proto"))
    (*(void (*)(t_chain*))option->action)(option->parameters);
  return (0);
}
