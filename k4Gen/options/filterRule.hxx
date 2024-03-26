#include "edm4hep/MCParticleCollection.h"

bool filterRule(const edm4hep::MCParticleCollection* inColl) {
  for(const auto& particle: *inColl) {
    // if (std::abs(particle.getPDG()) == 531) {    // Searches for the Bs0
    if ((std::abs(particle.getPDG()) % 1000) / 10 == 53) {    // Searches for all Bs
      double c = 2.998e+11;  // mm/s
      double dist = std::sqrt(
          std::pow(particle.getVertex().x - particle.getEndpoint().x, 2) +
          std::pow(particle.getVertex().y - particle.getEndpoint().y, 2) +
          std::pow(particle.getVertex().z - particle.getEndpoint().z, 2));
      double t = dist / c;
      /*
      std::cout << "PDG ID: " << particle.getPDG() << "\n";
      std::cout << "Vertex: x = " << particle.getVertex().x << "\n";
      std::cout << "        y = " << particle.getVertex().y << "\n";
      std::cout << "        z = " << particle.getVertex().z << "\n";
      std::cout << "End-point: x = " << particle.getEndpoint().x << "\n";
      std::cout << "           y = " << particle.getEndpoint().y << "\n";
      std::cout << "           z = " << particle.getEndpoint().z << "\n";
      std::cout << "Distance: " << dist << "\n";
      std::cout << "Time: " << t << std::endl;
      */
      // if (dist > 3.) {  // mm
      if (t > 3e-11) {  // s
        return true;
      }
    }
  }

  return false;
}
