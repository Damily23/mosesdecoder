#pragma once

#include <map>
#include "GibbsOperator.h"
#include "ScoreComponentCollection.h"

namespace Moses {

class Hypothesis;
class TranslationOptionCollection;

class Sample {
 private:
  int source_size;
  Hypothesis* target_head;
  Hypothesis* target_tail;

  Hypothesis* source_head;
  Hypothesis* source_tail;

  ScoreComponentCollection feature_values;
  
  std::map<size_t, Hypothesis*>  sourceIndexedHyps;

 public:
  Sample(Hypothesis* target_head);
  int GetSourceSize() { return source_size; }
  Hypothesis* GetHypAtSourceIndex(size_t );
  const Hypothesis* GetSampleHypothesis() const {
    return source_head;
  }
};

class Sampler {
 private:

 public:
  void Run(Hypothesis* starting, const TranslationOptionCollection* options) ;

};

/**
  * Used by the operators to collect samples, for example to count ngrams, or just to print
  * them out. 
  **/
class SampleCollector {
  public:
    virtual void collect(Sample& sample) = 0;
};

class PrintSampleCollector  : public virtual SampleCollector {
  public:
    virtual void collect(Sample& sample);
};

}



