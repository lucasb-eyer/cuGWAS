cuGWAS
======

High-performance GWAS implementation based on CUDA/cuBLAS. This is the code from my diploma (eq. masters) thesis. (Sorry AMD, no more time :-()

Since the paper is written now, I "only" need to extract the code from a bigger unreleased codebase and make it useable standalone. This may take a little time.

Installation
============
TODO

Usage
=====
TODO

Terminology
===========
The names of the variables used in my paper slightly differ from those used both in my code and in the [ProbABEL](http://www.biomedcentral.com/1471-2105/11/134) paper which describes the origin of the mathematics.
This is because I want the code to be closer to the ProbABEL paper, so it is more straightforward to interested users.
The correspondences are the following:

- In general, `x` suffixes correspond to `l` in the paper while `g` suffixes correspond to `r` in the paper. Thus `Xx` corresponds to `Xl`.
- `R`, `Rb` and similar correspond to `y` in the paper.
- `V` corresponds to `M` in the paper.
- `B`, `beta` and similar correspond to `r` in the paper.
