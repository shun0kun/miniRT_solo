# miniRT development

## MEMO
- 現状のget_next_lineはmalloc失敗を検知することができない。read失敗も。→ exitするのも1つの案。
- 入力のオーバーフロー判定までやるのか。
- sceneとparserを合体させる。同じモジュールにする。
- EPSILON作る。parserのunit vec3の比較条件文とかでも。
- hookに渡すポインタは、t_mlx_hook_argみたいな感じにする。渡したいもの(sceneとかimageとか)をポインタとして入れる感じ。
- parserのif文羅列方式は、テーブル駆動方式に変えるのもあり。コードがかなり短くなる。norminette対策にもなる。