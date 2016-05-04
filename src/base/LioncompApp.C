#include "LioncompApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<LioncompApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

LioncompApp::LioncompApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  LioncompApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  LioncompApp::associateSyntax(_syntax, _action_factory);
}

LioncompApp::~LioncompApp()
{
}

// External entry point for dynamic application loading
extern "C" void LioncompApp__registerApps() { LioncompApp::registerApps(); }
void
LioncompApp::registerApps()
{
  registerApp(LioncompApp);
}

// External entry point for dynamic object registration
extern "C" void LioncompApp__registerObjects(Factory & factory) { LioncompApp::registerObjects(factory); }
void
LioncompApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void LioncompApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { LioncompApp::associateSyntax(syntax, action_factory); }
void
LioncompApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
