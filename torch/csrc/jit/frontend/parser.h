
copy: fbcode/caffe2/torch/csrc/jit/frontend/parser.h
copyrev: e398d6b7cae5b88de39d343c787be6274f8f765a

#pragma once
#include <torch/csrc/WindowsTorchApiMacro.h>
#include <torch/csrc/jit/frontend/tree.h>
#include <torch/csrc/jit/frontend/tree_views.h>
#include <memory>

namespace torch {
namespace jit {
namespace script {

struct Decl;
struct ParserImpl;
struct Lexer;

TORCH_API Decl mergeTypesFromTypeComment(
    const Decl& decl,
    const Decl& type_annotation_decl,
    bool is_method);

struct TORCH_API Parser {
  explicit Parser(const std::shared_ptr<Source>& src);
  TreeRef parseFunction(bool is_method);
  TreeRef parseClass();
  Decl parseTypeComment();
  Expr parseExp();
  Lexer& lexer();
  ~Parser();

 private:
  std::unique_ptr<ParserImpl> pImpl;
};

} // namespace script
} // namespace jit
} // namespace torch
