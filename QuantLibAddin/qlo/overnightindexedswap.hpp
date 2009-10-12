/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
 Copyright (C) 2009 Ferdinando Ametrano

 This file is part of QuantLib, a free-software/open-source library
 for financial quantitative analysts and developers - http://quantlib.org/

 QuantLib is free software: you can redistribute it and/or modify it
 under the terms of the QuantLib license.  You should have received a
 copy of the license along with this program; if not, please email
 <quantlib-dev@lists.sf.net>. The license is also available online at
 <http://quantlib.org/license.shtml>.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
*/

#ifndef qla_overnightindexedswap_hpp
#define qla_overnightindexedswap_hpp

#include <qlo/swap.hpp>
#include <ql/experimental/overnightswap/overnightindexedswap.hpp>

namespace QuantLib {
    class OISRateHelper;
}

namespace QuantLibAddin {

    class OvernightIndexedSwap : public Swap {
    public:
        OvernightIndexedSwap(
            const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
            QuantLib::OvernightIndexedSwap::Type type,
            QuantLib::Real nominal,
            const boost::shared_ptr<QuantLib::Schedule>& schedule,
            QuantLib::Rate fixedRate,
            const QuantLib::DayCounter& fixedDC,
            const boost::shared_ptr<QuantLib::OvernightIndex>& overnightIndex,
            QuantLib::Spread overnightSpread,
            bool permanent);
        OvernightIndexedSwap( // MakeOIS
            const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
            QuantLib::OvernightIndexedSwap::Type type,
            QuantLib::Real nominal,
            const QuantLib::Date& startDate,
            const QuantLib::Period& tenor,
            QuantLib::Frequency paymentFrequency,
            QuantLib::Rate fixedRate,
            const QuantLib::DayCounter& fixedDC,
            const boost::shared_ptr<QuantLib::OvernightIndex>& overnightIndex,
            QuantLib::Spread overnightSpread,
            bool permanent);
        OvernightIndexedSwap( // MakeOIS
            const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
            QuantLib::OvernightIndexedSwap::Type type,
            QuantLib::Real nominal,
            const QuantLib::Date& startDate,
            const QuantLib::Date& enddate,
            QuantLib::Frequency paymentFrequency,
            QuantLib::Rate fixedRate,
            const QuantLib::DayCounter& fixedDC,
            const boost::shared_ptr<QuantLib::OvernightIndex>& overnightIndex,
            QuantLib::Spread overnightSpread,
            bool permanent);
        // Index constructor here
        OvernightIndexedSwap(
            const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
            const boost::shared_ptr<QuantLib::OISRateHelper>& swapRH,
            bool permanent);
        std::vector<std::vector<ObjectHandler::property_t> > fixedLegAnalysis();
        std::vector<std::vector<ObjectHandler::property_t> > overnightLegAnalysis();
    };

}

#endif