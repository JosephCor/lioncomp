#ifndef LIONCOMPAPP_H
#define LIONCOMPAPP_H

#include "MooseApp.h"

class LioncompApp;

template<>
InputParameters validParams<LioncompApp>();

class LioncompApp : public MooseApp
{
public:
  LioncompApp(InputParameters parameters);
  virtual ~LioncompApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* LIONCOMPAPP_H */
