/*
 * This file is part of the SYMPLER package.
 * https://github.com/kauzlari/sympler
 *
 * Copyright 2002-2018, 
 * David Kauzlaric <david.kauzlaric@imtek.uni-freiburg.de>,
 * and others authors stated in the AUTHORS file in the top-level 
 * source directory.
 *
 * SYMPLER is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * SYMPLER is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with SYMPLER.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Please cite the research papers on SYMPLER in your own publications. 
 * Check out the PUBLICATIONS file in the top-level source directory.
 *
 * You are very welcome to contribute extensions to the code. Please do 
 * so by making a pull request on https://github.com/kauzlari/sympler
 * 
 */

#include "cbl_pair_particle_vectorTest.h"

#include "simulation.h"

CPPUNIT_TEST_SUITE_REGISTRATION (CblPairParticleVectorTest);

void CblPairParticleVectorTest :: setUp (void)
{
  /*!
   * Initialize objects
   */
  Simulation* sim = new Simulation();
  
  m_callable = new CblPairParticleVector(sim);
}

void CblPairParticleVectorTest :: tearDown (void) 
{
  /*!
   * Delete objects
   */
  delete m_callable;
}

void CblPairParticleVectorTest :: initTest (void)
{
  /*!
   * Test init function. init() should have been called in constructor.
   */

  CblPairParticleArbitraryTest :: initTest();
  
  const PropertyList& properties = m_callable -> returnProperties();

  CPPUNIT_ASSERT_EQUAL
    (string("CblPairParticleVector"), m_callable -> name());
  CPPUNIT_ASSERT_EQUAL
    (string("CblPairParticleVector"), m_callable -> className());
  CPPUNIT_ASSERT_EQUAL
    (string("idVec(1)"), m_callable -> returnPairExpression());
  CPPUNIT_ASSERT_EQUAL
    (string("idVec(1)"), m_callable -> return1stParticleExpression());
  CPPUNIT_ASSERT_EQUAL
    (string("idVec(1)"), m_callable -> return2ndParticleExpression());
  
}

