#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 19
#define LARGE_STATE_COUNT 4
#define SYMBOL_COUNT 18
#define ALIAS_COUNT 0
#define TOKEN_COUNT 12
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 2
#define MAX_ALIAS_SEQUENCE_LENGTH 6
#define PRODUCTION_ID_COUNT 3

enum {
  anon_sym_POUND = 1,
  aux_sym_comment_token1 = 2,
  anon_sym_LF = 3,
  aux_sym_node_token1 = 4,
  aux_sym_error_node_token1 = 5,
  anon_sym_ = 6,
  anon_sym_COLON = 7,
  anon_sym_2 = 8,
  sym_key = 9,
  sym_value = 10,
  sym_blank_line = 11,
  sym_source_file = 12,
  sym_comment = 13,
  sym_node = 14,
  sym_error_node = 15,
  sym_property = 16,
  aux_sym_source_file_repeat1 = 17,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_POUND] = "#",
  [aux_sym_comment_token1] = "comment_token1",
  [anon_sym_LF] = "\n",
  [aux_sym_node_token1] = "node_token1",
  [aux_sym_error_node_token1] = "error_node_token1",
  [anon_sym_] = "    ",
  [anon_sym_COLON] = ":",
  [anon_sym_2] = " ",
  [sym_key] = "key",
  [sym_value] = "value",
  [sym_blank_line] = "blank_line",
  [sym_source_file] = "source_file",
  [sym_comment] = "comment",
  [sym_node] = "node",
  [sym_error_node] = "error_node",
  [sym_property] = "property",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_POUND] = anon_sym_POUND,
  [aux_sym_comment_token1] = aux_sym_comment_token1,
  [anon_sym_LF] = anon_sym_LF,
  [aux_sym_node_token1] = aux_sym_node_token1,
  [aux_sym_error_node_token1] = aux_sym_error_node_token1,
  [anon_sym_] = anon_sym_,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_2] = anon_sym_2,
  [sym_key] = sym_key,
  [sym_value] = sym_value,
  [sym_blank_line] = sym_blank_line,
  [sym_source_file] = sym_source_file,
  [sym_comment] = sym_comment,
  [sym_node] = sym_node,
  [sym_error_node] = sym_error_node,
  [sym_property] = sym_property,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_POUND] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_comment_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_LF] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_node_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_error_node_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_2] = {
    .visible = true,
    .named = false,
  },
  [sym_key] = {
    .visible = true,
    .named = true,
  },
  [sym_value] = {
    .visible = true,
    .named = true,
  },
  [sym_blank_line] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_node] = {
    .visible = true,
    .named = true,
  },
  [sym_error_node] = {
    .visible = true,
    .named = true,
  },
  [sym_property] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum {
  field_key = 1,
  field_value = 2,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_key] = "key",
  [field_value] = "value",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 2},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_key, 1},
  [1] =
    {field_key, 1},
    {field_value, 4},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(10);
      if (lookahead == '#') ADVANCE(11);
      if (lookahead == ':') ADVANCE(19);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (lookahead != 0) ADVANCE(16);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(25);
      if (lookahead == ' ') ADVANCE(4);
      if (lookahead == '#') ADVANCE(11);
      if (lookahead == '\t' ||
          lookahead == '\r') SKIP(1)
      if (lookahead != 0 &&
          lookahead != ':') ADVANCE(16);
      END_STATE();
    case 2:
      if (lookahead == '\n') ADVANCE(25);
      if (lookahead == ' ') ADVANCE(18);
      if (lookahead == '#') ADVANCE(11);
      if (lookahead == '\t' ||
          lookahead == '\r') SKIP(1)
      if (lookahead != 0 &&
          lookahead != ':') ADVANCE(16);
      END_STATE();
    case 3:
      if (lookahead == '\n') ADVANCE(25);
      if (lookahead == ' ') ADVANCE(2);
      if (lookahead == '#') ADVANCE(11);
      if (lookahead == '\t' ||
          lookahead == '\r') SKIP(1)
      if (lookahead != 0 &&
          lookahead != ':') ADVANCE(16);
      END_STATE();
    case 4:
      if (lookahead == '\n') ADVANCE(25);
      if (lookahead == ' ') ADVANCE(3);
      if (lookahead == '#') ADVANCE(11);
      if (lookahead == '\t' ||
          lookahead == '\r') SKIP(1)
      if (lookahead != 0 &&
          lookahead != ':') ADVANCE(16);
      END_STATE();
    case 5:
      if (lookahead == '\n') ADVANCE(14);
      if (lookahead == ' ') ADVANCE(20);
      if (lookahead == '\t' ||
          lookahead == '\r') SKIP(5)
      END_STATE();
    case 6:
      if (lookahead == '\n') ADVANCE(15);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(6)
      END_STATE();
    case 7:
      if (lookahead == '\n') SKIP(7)
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(21);
      if (lookahead != 0 &&
          lookahead != ':') ADVANCE(22);
      END_STATE();
    case 8:
      if (lookahead == '\n') SKIP(8)
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(23);
      if (lookahead != 0) ADVANCE(24);
      END_STATE();
    case 9:
      if (eof) ADVANCE(10);
      if (lookahead == '\n') ADVANCE(25);
      if (lookahead == ' ') ADVANCE(4);
      if (lookahead == '#') ADVANCE(11);
      if (lookahead == '\t' ||
          lookahead == '\r') SKIP(9)
      if (lookahead != 0 &&
          lookahead != ':') ADVANCE(16);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(anon_sym_POUND);
      if (lookahead == ':') ADVANCE(17);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(16);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(12);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(13);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(13);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(14);
      if (lookahead == ' ') ADVANCE(20);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(15);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(aux_sym_node_token1);
      if (lookahead == ':') ADVANCE(17);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(16);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(aux_sym_error_node_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(17);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(anon_sym_);
      if (lookahead == '\n') ADVANCE(25);
      if (lookahead == ' ') ADVANCE(18);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_2);
      if (lookahead == '\n') ADVANCE(14);
      if (lookahead == ' ') ADVANCE(20);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(sym_key);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(21);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ':') ADVANCE(22);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(sym_key);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ':') ADVANCE(22);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(sym_value);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(23);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(24);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(sym_value);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(24);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(sym_blank_line);
      if (lookahead == '\n') ADVANCE(25);
      if (lookahead == ' ') ADVANCE(4);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 9},
  [2] = {.lex_state = 9},
  [3] = {.lex_state = 9},
  [4] = {.lex_state = 9},
  [5] = {.lex_state = 9},
  [6] = {.lex_state = 9},
  [7] = {.lex_state = 9},
  [8] = {.lex_state = 9},
  [9] = {.lex_state = 5},
  [10] = {.lex_state = 12},
  [11] = {.lex_state = 6},
  [12] = {.lex_state = 6},
  [13] = {.lex_state = 7},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 6},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 8},
  [18] = {.lex_state = 6},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_POUND] = ACTIONS(1),
    [aux_sym_node_token1] = ACTIONS(1),
    [aux_sym_error_node_token1] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(14),
    [sym_comment] = STATE(2),
    [sym_node] = STATE(2),
    [sym_error_node] = STATE(2),
    [sym_property] = STATE(2),
    [aux_sym_source_file_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_POUND] = ACTIONS(5),
    [aux_sym_node_token1] = ACTIONS(7),
    [aux_sym_error_node_token1] = ACTIONS(9),
    [anon_sym_] = ACTIONS(11),
    [sym_blank_line] = ACTIONS(13),
  },
  [2] = {
    [sym_comment] = STATE(3),
    [sym_node] = STATE(3),
    [sym_error_node] = STATE(3),
    [sym_property] = STATE(3),
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(15),
    [anon_sym_POUND] = ACTIONS(5),
    [aux_sym_node_token1] = ACTIONS(7),
    [aux_sym_error_node_token1] = ACTIONS(9),
    [anon_sym_] = ACTIONS(11),
    [sym_blank_line] = ACTIONS(17),
  },
  [3] = {
    [sym_comment] = STATE(3),
    [sym_node] = STATE(3),
    [sym_error_node] = STATE(3),
    [sym_property] = STATE(3),
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(19),
    [anon_sym_POUND] = ACTIONS(21),
    [aux_sym_node_token1] = ACTIONS(24),
    [aux_sym_error_node_token1] = ACTIONS(27),
    [anon_sym_] = ACTIONS(30),
    [sym_blank_line] = ACTIONS(33),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 2,
    ACTIONS(36), 1,
      ts_builtin_sym_end,
    ACTIONS(38), 5,
      anon_sym_POUND,
      aux_sym_node_token1,
      aux_sym_error_node_token1,
      anon_sym_,
      sym_blank_line,
  [11] = 2,
    ACTIONS(40), 1,
      ts_builtin_sym_end,
    ACTIONS(42), 5,
      anon_sym_POUND,
      aux_sym_node_token1,
      aux_sym_error_node_token1,
      anon_sym_,
      sym_blank_line,
  [22] = 2,
    ACTIONS(44), 1,
      ts_builtin_sym_end,
    ACTIONS(46), 5,
      anon_sym_POUND,
      aux_sym_node_token1,
      aux_sym_error_node_token1,
      anon_sym_,
      sym_blank_line,
  [33] = 2,
    ACTIONS(48), 1,
      ts_builtin_sym_end,
    ACTIONS(50), 5,
      anon_sym_POUND,
      aux_sym_node_token1,
      aux_sym_error_node_token1,
      anon_sym_,
      sym_blank_line,
  [44] = 2,
    ACTIONS(52), 1,
      ts_builtin_sym_end,
    ACTIONS(54), 5,
      anon_sym_POUND,
      aux_sym_node_token1,
      aux_sym_error_node_token1,
      anon_sym_,
      sym_blank_line,
  [55] = 2,
    ACTIONS(56), 1,
      anon_sym_LF,
    ACTIONS(58), 1,
      anon_sym_2,
  [62] = 1,
    ACTIONS(60), 1,
      aux_sym_comment_token1,
  [66] = 1,
    ACTIONS(62), 1,
      anon_sym_LF,
  [70] = 1,
    ACTIONS(64), 1,
      anon_sym_LF,
  [74] = 1,
    ACTIONS(66), 1,
      sym_key,
  [78] = 1,
    ACTIONS(68), 1,
      ts_builtin_sym_end,
  [82] = 1,
    ACTIONS(70), 1,
      anon_sym_LF,
  [86] = 1,
    ACTIONS(72), 1,
      anon_sym_COLON,
  [90] = 1,
    ACTIONS(74), 1,
      sym_value,
  [94] = 1,
    ACTIONS(76), 1,
      anon_sym_LF,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(4)] = 0,
  [SMALL_STATE(5)] = 11,
  [SMALL_STATE(6)] = 22,
  [SMALL_STATE(7)] = 33,
  [SMALL_STATE(8)] = 44,
  [SMALL_STATE(9)] = 55,
  [SMALL_STATE(10)] = 62,
  [SMALL_STATE(11)] = 66,
  [SMALL_STATE(12)] = 70,
  [SMALL_STATE(13)] = 74,
  [SMALL_STATE(14)] = 78,
  [SMALL_STATE(15)] = 82,
  [SMALL_STATE(16)] = 86,
  [SMALL_STATE(17)] = 90,
  [SMALL_STATE(18)] = 94,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [19] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [21] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(10),
  [24] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(11),
  [27] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(12),
  [30] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(13),
  [33] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(3),
  [36] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node, 2),
  [38] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_node, 2),
  [40] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_error_node, 2),
  [42] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_error_node, 2),
  [44] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 3),
  [46] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_comment, 3),
  [48] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_property, 4, .production_id = 1),
  [50] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_property, 4, .production_id = 1),
  [52] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_property, 6, .production_id = 2),
  [54] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_property, 6, .production_id = 2),
  [56] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [58] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [60] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [62] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [64] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [66] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [68] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [70] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [72] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [74] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [76] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_gt(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
