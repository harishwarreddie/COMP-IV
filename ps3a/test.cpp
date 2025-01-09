// Copyright 2024 Harishwar Reddy Erri

#define BOOST_TEST_MODULE UniverseAndCelestialBodyTests
#include <cmath>
#include <sstream>
#include <boost/test/included/unit_test.hpp>
#include "Universe.hpp"
#include "CelestialBody.hpp"

BOOST_AUTO_TEST_CASE(UniverseAccessEntity) {
    NB::Universe u("planets.txt");
    BOOST_CHECK_NO_THROW(u.accessEntity(0));
    BOOST_CHECK_THROW(u.accessEntity(u.entityCount()), std::out_of_range);  // Use entityCount()
}

BOOST_AUTO_TEST_CASE(UniverseSetupScene) {
    NB::Universe u("planets.txt");
    BOOST_CHECK_NO_THROW(u.setupScene("image.png"));  // Assuming "image.png" exists
}

BOOST_AUTO_TEST_CASE(CelestialBodyInitializeAsset) {
    NB::CelestialBody body;
    body.setAssetId("earth.gif");
    BOOST_CHECK(body.initializeAsset());
}

BOOST_AUTO_TEST_CASE(CelestialBodyRefreshRepresentation) {
    NB::CelestialBody body;
    body.setAssetId("earth.gif");
    body.initializeAsset();
    BOOST_CHECK_NO_THROW(body.refreshRepresentation());
}

BOOST_AUTO_TEST_CASE(UniverseSetupAmbience) {
    NB::Universe u("planets.txt");
    BOOST_CHECK_NO_THROW(u.setupAmbience("music.wav"));  // Changed to check setupAmbience
}
