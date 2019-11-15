# cvpr2020
This directory contains all of the ARM computational kernels used the paper "Fast
Sparse ConvNets" submitted to CVPR 2020.

spmm-NxM-[scalar,neonfma].c - Sparse Matrix Multiplication with an unroll of N
in the HW dimension and a block size of M in the channel output dimension.

dwconv-KxKsSpP-[scalar,neonfma].c - Depthwise Convolution with a filter of KxK,
a stride of S and symmetric padding of P.

gavgpool-[scalar,neon]-xN.c - Global average pooling unrolled over N rows.

conv-3x3s2p1c3x4-[scalar,neonfma]-KxK - Full 3x3 stride 2 convolution with
HWC input and CHW output.  Operates on 3 input channels (only supported) and 4
output channels in the inner loop.  Produces a KxK output.

# TF-Lite Models

| Model | Top-1 Accuracy | Sparsity | Download |
|-------|----------------|----------|----------|
| MobileNetV1 .75  | 64.4% | 90% | [link](https://storage.googleapis.com/fast-convnets/tflite-models/mbv1_.75_12_90_64.4.tflite)
| MobileNetV1 1.0  | 68.4% | 90% | [link](https://storage.googleapis.com/fast-convnets/tflite-models/mbv1_1.0_12_90_68.4.tflite)
| MobileNetV1 1.4  | 72.0% | 90% | [link](https://storage.googleapis.com/fast-convnets/tflite-models/mbv1_1.4_12_90_72.0.tflite)
| MobileNetV2 .8   | 65.2% | 85% | [link](https://storage.googleapis.com/fast-convnets/tflite-models/mbv2_.80_11-16b2_85_65_2.tflite)
| MobileNetV2 1.15 | 70.2% | 85% | [link](https://storage.googleapis.com/fast-convnets/tflite-models/mbv2_1.15_11-16b2_85_70_2.tflite)
| MobileNetV2 1.4  | 72.0% | 85% | [link](https://storage.googleapis.com/fast-convnets/tflite-models/mbv2_1.4_11-16b2_85_72_0.tflite)
| MobileNetV2 1.8  | 74.9% | 80% | [link](https://storage.googleapis.com/fast-convnets/tflite-models/mbv2_1.8_x_80_74.9.tflite)
| MobileNetV2 2.0  | 74.5% | 85% | [link](https://storage.googleapis.com/fast-convnets/tflite-models/mbv2_2.0_11-16b2_85_74_5.tflite)