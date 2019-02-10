#ifndef __OpenViBEPlugins_BoxAlgorithm_CoherenceAnalysis_H__
#define __OpenViBEPlugins_BoxAlgorithm_CoherenceAnalysis_H__

//You may have to change this path to match your folder organisation
#include "ovp_defines.h"

#include <openvibe/ov_all.h>
#include <toolkit/ovtk_all.h>

// The unique identifiers for the box and its descriptor.
// Identifier are randomly chosen by the skeleton-generator.
#define OVP_ClassId_BoxAlgorithm_CoherenceAnalysis (0x58b145c6, 0xd4b88bbb)
#define OVP_ClassId_BoxAlgorithm_CoherenceAnalysisDesc (0x1322fb72, 0xa5ec8c9a)
#define OV_AttributeId_Box_FlagIsUnstable OpenViBE::CIdentifier(0x666FFFFF, 0x666FFFFF)


namespace OpenViBEPlugins
{
	namespace SignalProcessing
	{
		/**
		 * \class CBoxAlgorithmCoherenceAnalysis
		 * \author Alexey Minin (UrFU)
		 * \date Sun Feb 10 17:55:05 2019
		 * \brief The class CBoxAlgorithmCoherenceAnalysis describes the box Coherence analysis.
		 *
		 */
		class CBoxAlgorithmCoherenceAnalysis : virtual public OpenViBEToolkit::TBoxAlgorithm < OpenViBE::Plugins::IBoxAlgorithm >
		{
		public:
			virtual void release(void) { delete this; }

			virtual bool initialize(void);
			virtual bool uninitialize(void);
				
			//Here is the different process callbacks possible
			// - On clock ticks :
			//virtual bool processClock(OpenViBE::CMessageClock& rMessageClock);		
			// - On new input received (the most common behaviour for signal processing) :
			virtual bool processInput(uint32_t ui32InputIndex);
			
			// If you want to use processClock, you must provide the clock frequency.
			//virtual uint64_t getClockFrequency(void);
			
			virtual bool process(void);
			
			// As we do with any class in openvibe, we use the macro below 
			// to associate this box to an unique identifier. 
			// The inheritance information is also made available, 
			// as we provide the superclass OpenViBEToolkit::TBoxAlgorithm < OpenViBE::Plugins::IBoxAlgorithm >
			_IsDerivedFromClass_Final_(OpenViBEToolkit::TBoxAlgorithm < OpenViBE::Plugins::IBoxAlgorithm >, OVP_ClassId_BoxAlgorithm_CoherenceAnalysis);

		protected:
			// Input decoder:
			OpenViBEToolkit::TSpectrumDecoder < CBoxAlgorithmCoherenceAnalysis > m_oInput0Decoder;
			OpenViBEToolkit::TSpectrumDecoder < CBoxAlgorithmCoherenceAnalysis > m_oInput1Decoder;
			// Output decoder:
			OpenViBEToolkit::TStreamedMatrixEncoder < CBoxAlgorithmCoherenceAnalysis> m_oOutput0Encoder;

		};


		// If you need to implement a box Listener, here is a sekeleton for you.
		// Use only the callbacks you need.
		// For example, if your box has a variable number of input, but all of them must be stimulation inputs.
		// The following listener callback will ensure that any newly added input is stimulations :
		/*		
		virtual bool onInputAdded(OpenViBE::Kernel::IBox& rBox, const uint32_t ui32Index)
		{
			rBox.setInputType(ui32Index, OV_TypeId_Stimulations);
		};
		*/
		
		/*
		// The box listener can be used to call specific callbacks whenever the box structure changes : input added, name changed, etc.
		// Please uncomment below the callbacks you want to use.
		class CBoxAlgorithmCoherenceAnalysisListener : public OpenViBEToolkit::TBoxListener < OpenViBE::Plugins::IBoxListener >
		{
		public:

			//virtual bool onInitialized(OpenViBE::Kernel::IBox& rBox) { return true; };
			//virtual bool onNameChanged(OpenViBE::Kernel::IBox& rBox) { return true; };
			//virtual bool onInputConnected(OpenViBE::Kernel::IBox& rBox, const uint32_t ui32Index) { return true; };
			//virtual bool onInputDisconnected(OpenViBE::Kernel::IBox& rBox, const uint32_t ui32Index) { return true; };
			//virtual bool onInputAdded(OpenViBE::Kernel::IBox& rBox, const uint32_t ui32Index) { return true; };
			//virtual bool onInputRemoved(OpenViBE::Kernel::IBox& rBox, const uint32_t ui32Index) { return true; };
			//virtual bool onInputTypeChanged(OpenViBE::Kernel::IBox& rBox, const uint32_t ui32Index) { return true; };
			//virtual bool onInputNameChanged(OpenViBE::Kernel::IBox& rBox, const uint32_t ui32Index) { return true; };
			//virtual bool onOutputConnected(OpenViBE::Kernel::IBox& rBox, const uint32_t ui32Index) { return true; };
			//virtual bool onOutputDisconnected(OpenViBE::Kernel::IBox& rBox, const uint32_t ui32Index) { return true; };
			//virtual bool onOutputAdded(OpenViBE::Kernel::IBox& rBox, const uint32_t ui32Index) { return true; };
			//virtual bool onOutputRemoved(OpenViBE::Kernel::IBox& rBox, const uint32_t ui32Index) { return true; };
			//virtual bool onOutputTypeChanged(OpenViBE::Kernel::IBox& rBox, const uint32_t ui32Index) { return true; };
			//virtual bool onOutputNameChanged(OpenViBE::Kernel::IBox& rBox, const uint32_t ui32Index) { return true; };
			//virtual bool onSettingAdded(OpenViBE::Kernel::IBox& rBox, const uint32_t ui32Index) { return true; };
			//virtual bool onSettingRemoved(OpenViBE::Kernel::IBox& rBox, const uint32_t ui32Index) { return true; };
			//virtual bool onSettingTypeChanged(OpenViBE::Kernel::IBox& rBox, const uint32_t ui32Index) { return true; };
			//virtual bool onSettingNameChanged(OpenViBE::Kernel::IBox& rBox, const uint32_t ui32Index) { return true; };
			//virtual bool onSettingDefaultValueChanged(OpenViBE::Kernel::IBox& rBox, const uint32_t ui32Index) { return true; };
			//virtual bool onSettingValueChanged(OpenViBE::Kernel::IBox& rBox, const uint32_t ui32Index) { return true; };

			_IsDerivedFromClass_Final_(OpenViBEToolkit::TBoxListener < OpenViBE::Plugins::IBoxListener >, OV_UndefinedIdentifier);
		};
		*/

		/**
		 * \class CBoxAlgorithmCoherenceAnalysisDesc
		 * \author Alexey Minin (UrFU)
		 * \date Sun Feb 10 17:55:05 2019
		 * \brief Descriptor of the box Coherence analysis.
		 *
		 */
		class CBoxAlgorithmCoherenceAnalysisDesc : virtual public OpenViBE::Plugins::IBoxAlgorithmDesc
		{
		public:

			virtual void release(void) { }

			virtual OpenViBE::CString getName(void) const                { return OpenViBE::CString("Coherence analysis"); }
			virtual OpenViBE::CString getAuthorName(void) const          { return OpenViBE::CString("Alexey Minin"); }
			virtual OpenViBE::CString getAuthorCompanyName(void) const   { return OpenViBE::CString("UrFU"); }
			virtual OpenViBE::CString getShortDescription(void) const    { return OpenViBE::CString("Performs a Coherence Analysis"); }
			virtual OpenViBE::CString getDetailedDescription(void) const { return OpenViBE::CString("The box performs a coherent analysis of the signal spectrum (amplitude and phase), at the output of the box a matrix of coherence coefficients between channels"); }
			virtual OpenViBE::CString getCategory(void) const            { return OpenViBE::CString("Signal processing"); }
			virtual OpenViBE::CString getVersion(void) const             { return OpenViBE::CString("0.1.1"); }
			virtual OpenViBE::CString getStockItemName(void) const       { return OpenViBE::CString("gtk-file"); }

			virtual OpenViBE::CIdentifier getCreatedClass(void) const    { return OVP_ClassId_BoxAlgorithm_CoherenceAnalysis; }
			virtual OpenViBE::Plugins::IPluginObject* create(void)       { return new OpenViBEPlugins::SignalProcessing::CBoxAlgorithmCoherenceAnalysis; }
			
			/*
			virtual OpenViBE::Plugins::IBoxListener* createBoxListener(void) const               { return new CBoxAlgorithmCoherenceAnalysisListener; }
			virtual void releaseBoxListener(OpenViBE::Plugins::IBoxListener* pBoxListener) const { delete pBoxListener; }
			*/
			virtual bool getBoxPrototype(
				OpenViBE::Kernel::IBoxProto& rBoxAlgorithmPrototype) const
			{
				rBoxAlgorithmPrototype.addInput("Amplitude",OV_TypeId_Spectrum);
				rBoxAlgorithmPrototype.addInput("Phase",OV_TypeId_Spectrum);

				//rBoxAlgorithmPrototype.addFlag(OpenViBE::Kernel::BoxFlag_CanModifyInput);
				//rBoxAlgorithmPrototype.addFlag(OpenViBE::Kernel::BoxFlag_CanAddInput);
				
				rBoxAlgorithmPrototype.addOutput("Coherence matrix",OV_TypeId_StreamedMatrix);

				//rBoxAlgorithmPrototype.addFlag(OpenViBE::Kernel::BoxFlag_CanModifyOutput);
				//rBoxAlgorithmPrototype.addFlag(OpenViBE::Kernel::BoxFlag_CanAddOutput);

//No setting specified.To add settings use :
//rBoxAlgorithmPrototype.addSetting("SettingName",OV_TypeId_XXXX,"default value");

				//rBoxAlgorithmPrototype.addFlag(OpenViBE::Kernel::BoxFlag_CanModifySetting);
				//rBoxAlgorithmPrototype.addFlag(OpenViBE::Kernel::BoxFlag_CanAddSetting);
				
				rBoxAlgorithmPrototype.addFlag(OV_AttributeId_Box_FlagIsUnstable);
				
				return true;
			}
			_IsDerivedFromClass_Final_(OpenViBE::Plugins::IBoxAlgorithmDesc, OVP_ClassId_BoxAlgorithm_CoherenceAnalysisDesc);
		};
	};
};

#endif // __OpenViBEPlugins_BoxAlgorithm_CoherenceAnalysis_H__
