#ifndef N2O_COMPONENT_H
#define N2O_COMPONENT_H
/*
 *  n2o_component.hpp
 *  hector
 *
 *  Created by Ben on 05/19/2011.
 *
 */

#include "components/imodel_component.hpp"
#include "core/logger.hpp"
#include "data/tseries.hpp"
#include "data/unitval.hpp"

//------------------------------------------------------------------------------
/*! \brief Nitrous oxide model component.
 *
 *  This doesn't do much yet.
 */
class N2OComponent : public IModelComponent {
    friend class INIRestartVisitor; //!< To allow creation of a restart file.
    
public:
    N2OComponent();
    ~N2OComponent();
    
    //! IModelComponent methods
    virtual std::string getComponentName() const;
    
    virtual void init( Core* core );
    
    virtual unitval sendMessage( const std::string& message,
                                const std::string& datum,
                                const message_data info=message_data() ) throw ( h_exception );
    
    virtual void setData( const std::string& varName,
                          const message_data& data ) throw ( h_exception );
    
    virtual void prepareToRun() throw ( h_exception );
    
    virtual void run( const double runToDate ) throw ( h_exception );
    
    virtual void shutDown();
    
    //! IVisitable methods
    virtual void accept( AVisitor* visitor );
    
private:
    virtual unitval getData( const std::string& varName,
                            const double date ) throw ( h_exception );
    
    unitval N0;    //!< preindustrial nitrous oxide
    //! Concentration time series
	tseries<unitval> Na;
    
    //! logger
    Logger logger;

	Core *core;
    double oldDate;
};

#endif // N2O_COMPONENT_H