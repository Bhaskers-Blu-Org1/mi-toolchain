/*!
 * \file EpisodicTrainAndTestApplication.hpp
 * \brief 
 * \author tkornut
 * \date Feb 17, 2016
 */

#ifndef SRC_APPLICATION_EPISODICTRAINANDTESTAPPLICATION_HPP_
#define SRC_APPLICATION_EPISODICTRAINANDTESTAPPLICATION_HPP_

#include <application/Application.hpp>

namespace mic {
namespace application {

/*!
 * \brief Parent class for all applications basing on episodes. Each episode consists of two phases: a training phase (first), and testing phase (second). Each phase will end when then an adequate method (performLearning/TrainingStep) will return false.
 * \author tkornuta
 * \date Jan 11, 2016
 */
class EpisodicTrainAndTestApplication : public mic::application::Application {
public:
	/*!
	 * Default constructor. Sets the application/node name and registers properties.
	 * @param node_name_ Name of the application/node (in configuration file).
	 */
	EpisodicTrainAndTestApplication(std::string node_name_);

	/*!
	 * Default destructor - empty.
	 */
	virtual ~EpisodicTrainAndTestApplication() { };

	/*!
	 * Main application method - handles single step/pause/quite modes/commands. Calls performSingleStep().
	 */
	void run();


protected:
	/*!
	 * Performs single step of computations. Depending on the state, calls learning or testing step - switches from learning to testing then learning return false - everything in the scope of a given episode.
	 */
	virtual bool performSingleStep();

	/*!
	 * Perform learning step - abstract, to be overridden.
	 * @return Returns false when test learning is completed.
	 */
	virtual bool performLearningStep() = 0;

	/*!
	 * Perform testing step - abstract, to be overridden.
	 * @return Returns false when test learning is completed.
	 */
	virtual bool performTestingStep() = 0;

	/*!
	 * Method called at the beginning of new episode (goal: to reset the statistics etc.) - abstract, to be overridden.
	 */
	virtual void startNewEpisode() = 0;

	/*!
	 * Method called when given episode ends (goal: export collected statistics to file etc.) - abstract, to be overridden.
	 */
	virtual void finishCurrentEpisode() = 0;

	/// Episode counter.
	unsigned long episode;

	/*!
	 * Property: number of episodes, after which the application will end. 0 (default value) deactivates terminal condition (unlimited number of episodes).
	 */
	mic::configuration::Property<unsigned long> number_of_episodes;


};

} /* namespace application */
} /* namespace mic */

#endif /* SRC_APPLICATION_EPISODICTRAINANDTESTAPPLICATION_HPP_ */
