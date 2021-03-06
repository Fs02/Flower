#ifndef FLOWER_DROPOUT_H
#define FLOWER_DROPOUT_H

#include <flower/layer.h>

namespace flower
{
    class Dropout : public ILayerDef
    {
    public:
        Dropout(double probability = 0.5);

        inline const char *type() const { return "Dropout"; }

        inline double probability() const { return probability_; }

        double probability_;

    protected:
        layer_ptr create(Net *net) const;
    };

    class DropoutLayer : public ILayer
    {
    public:
        explicit DropoutLayer(Net *net, const Dropout &definition);

        inline const char *type() const { return "Dropout"; }

        Eigen::Tensor<double, 2> forward(const Eigen::Tensor<double, 2> &data, bool train = false);
        Eigen::Tensor<double, 2> backward(const Eigen::Tensor<double, 2> &errors);

    protected:
        Eigen::Tensor<double, 2> mask_;
        double probability_;
    };
}

#endif
