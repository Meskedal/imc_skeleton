#include <IMC/Spec/PlanManeuver.hpp>
#include <IMC/Spec/PlanSpecification.hpp>
#include <IMC/Spec/SetEntityParameters.hpp>
#include <IMC/Spec/Loiter.hpp>
#include <IMC/Spec/EntityParameter.hpp>
// #define LAUVXPLORE1 (30)
// using namespace IMC;

int main(void) {
    char localhost[] = "127.0.0.1";
    IMC::PlanSpecification planSpecification;
    IMC::PlanManeuver planManeuver;
    IMC::Loiter loiter;
    IMC::SetEntityParameters setEntityParameters;
    IMC::EntityParameter entityParameters;

    planSpecification.setTimeStamp(1.5628304294681385E9);
    planSpecification.setSource(16652);
    planSpecification.setSourceEntity(44);
    planSpecification.setDestination(30);
    planSpecification.setDestinationEntity(255);
    planSpecification.plan_id = "cmd-lauv-xplore-1";
    planSpecification.start_man_id = "1";

    planManeuver.maneuver_id = "1";

    loiter.timeout = 10000;
    planManeuver.data.set(loiter);
    // And so on for the other paramters 
    planSpecification.maneuvers.push_back(planManeuver);
    setEntityParameters.params.push_back(entityParameters);
    planSpecification.start_actions.push_back(setEntityParameters);
    // Prints as JSON
    std::cout << planSpecification.toString();

    return 0;
}