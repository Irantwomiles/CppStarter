#include <fmt/format.h>
#include <greeter/greeter.h>
#include <iostream>
#include <proj.h>

using namespace greeter;

Greeter::Greeter(std::string _name) : name(std::move(_name)) {}

void Test_Proj() {

  PJ_CONTEXT *C;
  PJ *P;
  PJ *norm;
  PJ_COORD a, b;

  C = proj_context_create();

  P = proj_create_crs_to_crs (C,
                             "EPSG:4326",
                             "+proj=utm +zone=32 +datum=WGS84", /* or EPSG:32632 */
                             NULL);

  if (0 == P) {
    fprintf(stderr, "Failed to create transformation object.\n");
    std::cout << "Failed to create transformation object" << std::endl;
    return;
  }

  std::cout << P << std::endl;

}

std::string Greeter::greet(LanguageCode lang) const {
  switch (lang) {
    default:
    case LanguageCode::EN:
      return fmt::format("Hello, {}!", name);
    case LanguageCode::DE:
      return fmt::format("Hallo {}!", name);
    case LanguageCode::ES:
      return fmt::format("¡Hola {}!", name);
    case LanguageCode::FR:
      return fmt::format("Bonjour {}!", name);
  }
}
