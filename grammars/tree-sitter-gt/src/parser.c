#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 16
#define LARGE_STATE_COUNT 4
#define SYMBOL_COUNT 15
#define ALIAS_COUNT 0
#define TOKEN_COUNT 10
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 2
#define MAX_ALIAS_SEQUENCE_LENGTH 6
#define PRODUCTION_ID_COUNT 3

enum {
  aux_sym_node_token1 = 1,
  anon_sym_LF = 2,
  aux_sym_error_node_token1 = 3,
  anon_sym_ = 4,
  anon_sym_COLON = 5,
  anon_sym_2 = 6,
  sym_key = 7,
  sym_value = 8,
  sym_blank_line = 9,
  sym_source_file = 10,
  sym_node = 11,
  sym_error_node = 12,
  sym_property = 13,
  aux_sym_source_file_repeat1 = 14,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [aux_sym_node_token1] = "node_token1",
  [anon_sym_LF] = "\n",
  [aux_sym_error_node_token1] = "error_node_token1",
  [anon_sym_] = "    ",
  [anon_sym_COLON] = ":",
  [anon_sym_2] = " ",
  [sym_key] = "key",
  [sym_value] = "value",
  [sym_blank_line] = "blank_line",
  [sym_source_file] = "source_file",
  [sym_node] = "node",
  [sym_error_node] = "error_node",
  [sym_property] = "property",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [aux_sym_node_token1] = aux_sym_node_token1,
  [anon_sym_LF] = anon_sym_LF,
  [aux_sym_error_node_token1] = aux_sym_error_node_token1,
  [anon_sym_] = anon_sym_,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_2] = anon_sym_2,
  [sym_key] = sym_key,
  [sym_value] = sym_value,
  [sym_blank_line] = sym_blank_line,
  [sym_source_file] = sym_source_file,
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
  [aux_sym_node_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_LF] = {
    .visible = true,
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(10);
      if (lookahead == ':') ADVANCE(16);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (lookahead != 0) ADVANCE(11);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(22);
      if (lookahead == ' ') ADVANCE(4);
      if (lookahead == '\t' ||
          lookahead == '\r') SKIP(1)
      if (lookahead != 0 &&
          lookahead != ':') ADVANCE(11);
      END_STATE();
    case 2:
      if (lookahead == '\n') ADVANCE(22);
      if (lookahead == ' ') ADVANCE(15);
      if (lookahead == '\t' ||
          lookahead == '\r') SKIP(1)
      if (lookahead != 0 &&
          lookahead != ':') ADVANCE(11);
      END_STATE();
    case 3:
      if (lookahead == '\n') ADVANCE(22);
      if (lookahead == ' ') ADVANCE(2);
      if (lookahead == '\t' ||
          lookahead == '\r') SKIP(1)
      if (lookahead != 0 &&
          lookahead != ':') ADVANCE(11);
      END_STATE();
    case 4:
      if (lookahead == '\n') ADVANCE(22);
      if (lookahead == ' ') ADVANCE(3);
      if (lookahead == '\t' ||
          lookahead == '\r') SKIP(1)
      if (lookahead != 0 &&
          lookahead != ':') ADVANCE(11);
      END_STATE();
    case 5:
      if (lookahead == '\n') ADVANCE(12);
      if (lookahead == ' ') ADVANCE(17);
      if (lookahead == '\t' ||
          lookahead == '\r') SKIP(5)
      END_STATE();
    case 6:
      if (lookahead == '\n') ADVANCE(13);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(6)
      END_STATE();
    case 7:
      if (lookahead == '\n') SKIP(7)
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(18);
      if (lookahead != 0 &&
          lookahead != ':') ADVANCE(19);
      END_STATE();
    case 8:
      if (lookahead == '\n') SKIP(8)
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(20);
      if (lookahead != 0) ADVANCE(21);
      END_STATE();
    case 9:
      if (eof) ADVANCE(10);
      if (lookahead == '\n') ADVANCE(22);
      if (lookahead == ' ') ADVANCE(4);
      if (lookahead == '\t' ||
          lookahead == '\r') SKIP(9)
      if (lookahead != 0 &&
          lookahead != ':') ADVANCE(11);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(aux_sym_node_token1);
      if (lookahead == ':') ADVANCE(14);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(11);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(12);
      if (lookahead == ' ') ADVANCE(17);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(13);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(aux_sym_error_node_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(14);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(anon_sym_);
      if (lookahead == '\n') ADVANCE(22);
      if (lookahead == ' ') ADVANCE(15);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(anon_sym_2);
      if (lookahead == '\n') ADVANCE(12);
      if (lookahead == ' ') ADVANCE(17);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(sym_key);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(18);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ':') ADVANCE(19);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(sym_key);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ':') ADVANCE(19);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(sym_value);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(20);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(21);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(sym_value);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(21);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(sym_blank_line);
      if (lookahead == '\n') ADVANCE(22);
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
  [8] = {.lex_state = 5},
  [9] = {.lex_state = 6},
  [10] = {.lex_state = 6},
  [11] = {.lex_state = 7},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 8},
  [15] = {.lex_state = 6},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [aux_sym_node_token1] = ACTIONS(1),
    [aux_sym_error_node_token1] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(12),
    [sym_node] = STATE(2),
    [sym_error_node] = STATE(2),
    [sym_property] = STATE(2),
    [aux_sym_source_file_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(3),
    [aux_sym_node_token1] = ACTIONS(5),
    [aux_sym_error_node_token1] = ACTIONS(7),
    [anon_sym_] = ACTIONS(9),
    [sym_blank_line] = ACTIONS(11),
  },
  [2] = {
    [sym_node] = STATE(3),
    [sym_error_node] = STATE(3),
    [sym_property] = STATE(3),
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(13),
    [aux_sym_node_token1] = ACTIONS(5),
    [aux_sym_error_node_token1] = ACTIONS(7),
    [anon_sym_] = ACTIONS(9),
    [sym_blank_line] = ACTIONS(15),
  },
  [3] = {
    [sym_node] = STATE(3),
    [sym_error_node] = STATE(3),
    [sym_property] = STATE(3),
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(17),
    [aux_sym_node_token1] = ACTIONS(19),
    [aux_sym_error_node_token1] = ACTIONS(22),
    [anon_sym_] = ACTIONS(25),
    [sym_blank_line] = ACTIONS(28),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 2,
    ACTIONS(31), 1,
      ts_builtin_sym_end,
    ACTIONS(33), 4,
      aux_sym_node_token1,
      aux_sym_error_node_token1,
      anon_sym_,
      sym_blank_line,
  [10] = 2,
    ACTIONS(35), 1,
      ts_builtin_sym_end,
    ACTIONS(37), 4,
      aux_sym_node_token1,
      aux_sym_error_node_token1,
      anon_sym_,
      sym_blank_line,
  [20] = 2,
    ACTIONS(39), 1,
      ts_builtin_sym_end,
    ACTIONS(41), 4,
      aux_sym_node_token1,
      aux_sym_error_node_token1,
      anon_sym_,
      sym_blank_line,
  [30] = 2,
    ACTIONS(43), 1,
      ts_builtin_sym_end,
    ACTIONS(45), 4,
      aux_sym_node_token1,
      aux_sym_error_node_token1,
      anon_sym_,
      sym_blank_line,
  [40] = 2,
    ACTIONS(47), 1,
      anon_sym_LF,
    ACTIONS(49), 1,
      anon_sym_2,
  [47] = 1,
    ACTIONS(51), 1,
      anon_sym_LF,
  [51] = 1,
    ACTIONS(53), 1,
      anon_sym_LF,
  [55] = 1,
    ACTIONS(55), 1,
      sym_key,
  [59] = 1,
    ACTIONS(57), 1,
      ts_builtin_sym_end,
  [63] = 1,
    ACTIONS(59), 1,
      anon_sym_COLON,
  [67] = 1,
    ACTIONS(61), 1,
      sym_value,
  [71] = 1,
    ACTIONS(63), 1,
      anon_sym_LF,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(4)] = 0,
  [SMALL_STATE(5)] = 10,
  [SMALL_STATE(6)] = 20,
  [SMALL_STATE(7)] = 30,
  [SMALL_STATE(8)] = 40,
  [SMALL_STATE(9)] = 47,
  [SMALL_STATE(10)] = 51,
  [SMALL_STATE(11)] = 55,
  [SMALL_STATE(12)] = 59,
  [SMALL_STATE(13)] = 63,
  [SMALL_STATE(14)] = 67,
  [SMALL_STATE(15)] = 71,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [13] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [17] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [19] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(9),
  [22] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(10),
  [25] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(11),
  [28] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(3),
  [31] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node, 2),
  [33] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_node, 2),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_error_node, 2),
  [37] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_error_node, 2),
  [39] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_property, 4, .production_id = 1),
  [41] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_property, 4, .production_id = 1),
  [43] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_property, 6, .production_id = 2),
  [45] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_property, 6, .production_id = 2),
  [47] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [49] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [51] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [53] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [55] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [57] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [59] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [61] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [63] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
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
