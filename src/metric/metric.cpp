#include <LightGBM/metric.h>
#include "regression_metric.hpp"
#include "binary_metric.hpp"
#include "rank_metric.hpp"
#include "map_metric.hpp"
#include "multiclass_metric.hpp"

namespace LightGBM {

Metric* Metric::CreateMetric(const std::string& type, const MetricConfig& config) {
  if (type == std::string("l2") || type == std::string("mean_squared_error") || type == std::string("mse")) {
    return new L2Metric(config);
  } else if (type == std::string("l1") || type == std::string("mean_absolute_error")  || type == std::string("mae")) {
    return new L1Metric(config);
  } else if (type == std::string("huber")) {
    return new HuberLossMetric(config);
  } else if (type == std::string("fair")) {
    return new FairLossMetric(config);
  } else if (type == std::string("poisson")) {
    return new PoissonMetric(config);
  } else if (type == std::string("binary_logloss")) {
    return new BinaryLoglossMetric(config);
  } else if (type == std::string("binary_error")) {
    return new BinaryErrorMetric(config);
  } else if (type == std::string("auc")) {
    return new AUCMetric(config);
  } else if (type == std::string("ndcg")) {
    return new NDCGMetric(config);
  } else if (type == std::string("map")) {
    return new MapMetric(config);
  } else if (type == std::string("multi_logloss")) {
    return new MultiLoglossMetric(config);
  } else if (type == std::string("multi_error")) {
    return new MultiErrorMetric(config);
  }
  return nullptr;
}

}  // namespace LightGBM
