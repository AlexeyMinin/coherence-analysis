Coherence analysis plugin for OpenVibe system
=====================================
> Actual for version OpenVibe 2.2.0

This plugin contains the boxes:
  - Coherence analysis
  
The Coherence analysis box performs a coherent analysis of the signal spectrum (amplitude and phase), at the output of the box a matrix of coherence coefficients between channels.

Registering the plugin in system
-------------------
1. [Get](http://openvibe.inria.fr/repo-instructions/) OpenVibe system
2. Put this plugin to folder ***meta/extras/contrib/plugins/processing/signal-processing/src/***
    - Get an anonymous clone of the repository ***git clone https://github.com/AlexeyMinin/coherence-analysis.git***
    - Or simply download this repository
3. Edit ***meta/extras/contrib/plugins/processing/signal-processing/src/ovp_main.cpp*** in order to make this box available in the Designer. This look something like this:
    ```C++
    #include "coherence-analysis/ovpCBoxAlgorithmCoherenceAnalysis.h"
    ...
    OVP_Declare_Begin();
    ...
    OVP_Declare_New(OpenViBEPlugins::SignalProcessing::CBoxAlgorithmCoherenceAnalysisDesc);
    ...
    OVP_Declare_End();
    ```
4. [Build](http://openvibe.inria.fr/build-instructions/) OpenVibe system
