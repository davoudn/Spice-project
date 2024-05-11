// Generated from /media/pouyan/248C978C8C9756E0/Spice-project/codes/Parser/TParser.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class TParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		COMMENT=1, WHITESPACE=2, NEWLINE=3, RESISTOR_NAME=4, CAPACITOR_NAME=5, 
		INDUCTOR_NAME=6, MUTUAL_INDUCTOR_NAME=7, DIOD_NAME=8, COMPONENT_VALUE=9, 
		NUMERIC_VALUE=10, NUMBERS=11, END=12, PARAMS=13, TEXT=14;
	public static final int
		RULE_main = 0, RULE_resistor = 1, RULE_capacitor = 2, RULE_inductor = 3, 
		RULE_mutual_inductor = 4, RULE_diod = 5;
	private static String[] makeRuleNames() {
		return new String[] {
			"main", "resistor", "capacitor", "inductor", "mutual_inductor", "diod"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, null, null, null, 
			"'.end'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "COMMENT", "WHITESPACE", "NEWLINE", "RESISTOR_NAME", "CAPACITOR_NAME", 
			"INDUCTOR_NAME", "MUTUAL_INDUCTOR_NAME", "DIOD_NAME", "COMPONENT_VALUE", 
			"NUMERIC_VALUE", "NUMBERS", "END", "PARAMS", "TEXT"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "TParser.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public TParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class MainContext extends ParserRuleContext {
		public List<ResistorContext> resistor() {
			return getRuleContexts(ResistorContext.class);
		}
		public ResistorContext resistor(int i) {
			return getRuleContext(ResistorContext.class,i);
		}
		public List<CapacitorContext> capacitor() {
			return getRuleContexts(CapacitorContext.class);
		}
		public CapacitorContext capacitor(int i) {
			return getRuleContext(CapacitorContext.class,i);
		}
		public List<InductorContext> inductor() {
			return getRuleContexts(InductorContext.class);
		}
		public InductorContext inductor(int i) {
			return getRuleContext(InductorContext.class,i);
		}
		public MainContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_main; }
	}

	public final MainContext main() throws RecognitionException {
		MainContext _localctx = new MainContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_main);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(15);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==RESISTOR_NAME) {
				{
				{
				setState(12);
				resistor();
				}
				}
				setState(17);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(21);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==CAPACITOR_NAME) {
				{
				{
				setState(18);
				capacitor();
				}
				}
				setState(23);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(27);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==INDUCTOR_NAME) {
				{
				{
				setState(24);
				inductor();
				}
				}
				setState(29);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ResistorContext extends ParserRuleContext {
		public TerminalNode RESISTOR_NAME() { return getToken(TParser.RESISTOR_NAME, 0); }
		public List<TerminalNode> TEXT() { return getTokens(TParser.TEXT); }
		public TerminalNode TEXT(int i) {
			return getToken(TParser.TEXT, i);
		}
		public TerminalNode NEWLINE() { return getToken(TParser.NEWLINE, 0); }
		public List<TerminalNode> WHITESPACE() { return getTokens(TParser.WHITESPACE); }
		public TerminalNode WHITESPACE(int i) {
			return getToken(TParser.WHITESPACE, i);
		}
		public List<TerminalNode> NUMERIC_VALUE() { return getTokens(TParser.NUMERIC_VALUE); }
		public TerminalNode NUMERIC_VALUE(int i) {
			return getToken(TParser.NUMERIC_VALUE, i);
		}
		public List<TerminalNode> PARAMS() { return getTokens(TParser.PARAMS); }
		public TerminalNode PARAMS(int i) {
			return getToken(TParser.PARAMS, i);
		}
		public ResistorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_resistor; }
	}

	public final ResistorContext resistor() throws RecognitionException {
		ResistorContext _localctx = new ResistorContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_resistor);
		int _la;
		try {
			int _alt;
			setState(122);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,18,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				{
				setState(30);
				match(RESISTOR_NAME);
				setState(32); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(31);
					match(WHITESPACE);
					}
					}
					setState(34); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHITESPACE );
				setState(36);
				match(TEXT);
				setState(38); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(37);
					match(WHITESPACE);
					}
					}
					setState(40); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHITESPACE );
				setState(42);
				match(TEXT);
				setState(44); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(43);
					match(WHITESPACE);
					}
					}
					setState(46); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHITESPACE );
				setState(49); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(48);
					match(NUMERIC_VALUE);
					}
					}
					setState(51); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==NUMERIC_VALUE );
				setState(54); 
				_errHandler.sync(this);
				_alt = 1;
				do {
					switch (_alt) {
					case 1:
						{
						{
						setState(53);
						match(WHITESPACE);
						}
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					setState(56); 
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,7,_ctx);
				} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
				setState(61);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==PARAMS) {
					{
					{
					setState(58);
					match(PARAMS);
					}
					}
					setState(63);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(67);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WHITESPACE) {
					{
					{
					setState(64);
					match(WHITESPACE);
					}
					}
					setState(69);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(70);
				match(NEWLINE);
				}
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				{
				setState(71);
				match(RESISTOR_NAME);
				setState(73); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(72);
					match(WHITESPACE);
					}
					}
					setState(75); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHITESPACE );
				setState(77);
				match(TEXT);
				setState(79); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(78);
					match(WHITESPACE);
					}
					}
					setState(81); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHITESPACE );
				setState(83);
				match(TEXT);
				setState(85); 
				_errHandler.sync(this);
				_alt = 1;
				do {
					switch (_alt) {
					case 1:
						{
						{
						setState(84);
						match(WHITESPACE);
						}
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					setState(87); 
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
				} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
				setState(92);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==NUMERIC_VALUE) {
					{
					{
					setState(89);
					match(NUMERIC_VALUE);
					}
					}
					setState(94);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(98);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WHITESPACE) {
					{
					{
					setState(95);
					match(WHITESPACE);
					}
					}
					setState(100);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(101);
				match(NEWLINE);
				}
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				{
				setState(102);
				match(RESISTOR_NAME);
				setState(104); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(103);
					match(WHITESPACE);
					}
					}
					setState(106); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHITESPACE );
				setState(108);
				match(TEXT);
				setState(110); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(109);
					match(WHITESPACE);
					}
					}
					setState(112); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHITESPACE );
				setState(114);
				match(TEXT);
				setState(118);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WHITESPACE) {
					{
					{
					setState(115);
					match(WHITESPACE);
					}
					}
					setState(120);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(121);
				match(NEWLINE);
				}
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class CapacitorContext extends ParserRuleContext {
		public TerminalNode CAPACITOR_NAME() { return getToken(TParser.CAPACITOR_NAME, 0); }
		public List<TerminalNode> TEXT() { return getTokens(TParser.TEXT); }
		public TerminalNode TEXT(int i) {
			return getToken(TParser.TEXT, i);
		}
		public TerminalNode NEWLINE() { return getToken(TParser.NEWLINE, 0); }
		public List<TerminalNode> WHITESPACE() { return getTokens(TParser.WHITESPACE); }
		public TerminalNode WHITESPACE(int i) {
			return getToken(TParser.WHITESPACE, i);
		}
		public List<TerminalNode> NUMERIC_VALUE() { return getTokens(TParser.NUMERIC_VALUE); }
		public TerminalNode NUMERIC_VALUE(int i) {
			return getToken(TParser.NUMERIC_VALUE, i);
		}
		public List<TerminalNode> PARAMS() { return getTokens(TParser.PARAMS); }
		public TerminalNode PARAMS(int i) {
			return getToken(TParser.PARAMS, i);
		}
		public CapacitorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_capacitor; }
	}

	public final CapacitorContext capacitor() throws RecognitionException {
		CapacitorContext _localctx = new CapacitorContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_capacitor);
		int _la;
		try {
			int _alt;
			setState(288);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,46,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				{
				setState(124);
				match(CAPACITOR_NAME);
				setState(126); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(125);
					match(WHITESPACE);
					}
					}
					setState(128); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHITESPACE );
				setState(130);
				match(TEXT);
				setState(132); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(131);
					match(WHITESPACE);
					}
					}
					setState(134); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHITESPACE );
				setState(136);
				match(TEXT);
				setState(138); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(137);
					match(WHITESPACE);
					}
					}
					setState(140); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHITESPACE );
				setState(143); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(142);
					match(NUMERIC_VALUE);
					}
					}
					setState(145); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==NUMERIC_VALUE );
				setState(148); 
				_errHandler.sync(this);
				_alt = 1;
				do {
					switch (_alt) {
					case 1:
						{
						{
						setState(147);
						match(WHITESPACE);
						}
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					setState(150); 
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,23,_ctx);
				} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
				setState(155);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==PARAMS) {
					{
					{
					setState(152);
					match(PARAMS);
					}
					}
					setState(157);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(161);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WHITESPACE) {
					{
					{
					setState(158);
					match(WHITESPACE);
					}
					}
					setState(163);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(164);
				match(NEWLINE);
				}
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				{
				setState(165);
				match(CAPACITOR_NAME);
				setState(167); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(166);
					match(WHITESPACE);
					}
					}
					setState(169); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHITESPACE );
				setState(171);
				match(TEXT);
				setState(173); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(172);
					match(WHITESPACE);
					}
					}
					setState(175); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHITESPACE );
				setState(177);
				match(TEXT);
				setState(179); 
				_errHandler.sync(this);
				_alt = 1;
				do {
					switch (_alt) {
					case 1:
						{
						{
						setState(178);
						match(WHITESPACE);
						}
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					setState(181); 
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,28,_ctx);
				} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
				setState(186);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==NUMERIC_VALUE) {
					{
					{
					setState(183);
					match(NUMERIC_VALUE);
					}
					}
					setState(188);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(192);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WHITESPACE) {
					{
					{
					setState(189);
					match(WHITESPACE);
					}
					}
					setState(194);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(195);
				match(NEWLINE);
				}
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				{
				setState(196);
				match(CAPACITOR_NAME);
				setState(198); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(197);
					match(WHITESPACE);
					}
					}
					setState(200); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHITESPACE );
				setState(202);
				match(TEXT);
				setState(204); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(203);
					match(WHITESPACE);
					}
					}
					setState(206); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHITESPACE );
				setState(208);
				match(TEXT);
				setState(212);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WHITESPACE) {
					{
					{
					setState(209);
					match(WHITESPACE);
					}
					}
					setState(214);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(215);
				match(NEWLINE);
				}
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				{
				setState(216);
				match(CAPACITOR_NAME);
				setState(218); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(217);
					match(WHITESPACE);
					}
					}
					setState(220); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHITESPACE );
				setState(222);
				match(TEXT);
				setState(224); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(223);
					match(WHITESPACE);
					}
					}
					setState(226); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHITESPACE );
				setState(228);
				match(TEXT);
				setState(230); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(229);
					match(WHITESPACE);
					}
					}
					setState(232); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHITESPACE );
				setState(235); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(234);
					match(TEXT);
					}
					}
					setState(237); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==TEXT );
				setState(240); 
				_errHandler.sync(this);
				_alt = 1;
				do {
					switch (_alt) {
					case 1:
						{
						{
						setState(239);
						match(WHITESPACE);
						}
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					setState(242); 
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,38,_ctx);
				} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
				setState(247);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==PARAMS) {
					{
					{
					setState(244);
					match(PARAMS);
					}
					}
					setState(249);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(253);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WHITESPACE) {
					{
					{
					setState(250);
					match(WHITESPACE);
					}
					}
					setState(255);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(256);
				match(NEWLINE);
				}
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				{
				setState(257);
				match(CAPACITOR_NAME);
				setState(259); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(258);
					match(WHITESPACE);
					}
					}
					setState(261); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHITESPACE );
				setState(263);
				match(TEXT);
				setState(265); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(264);
					match(WHITESPACE);
					}
					}
					setState(267); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHITESPACE );
				setState(269);
				match(TEXT);
				setState(271); 
				_errHandler.sync(this);
				_alt = 1;
				do {
					switch (_alt) {
					case 1:
						{
						{
						setState(270);
						match(WHITESPACE);
						}
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					setState(273); 
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,43,_ctx);
				} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
				setState(278);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==TEXT) {
					{
					{
					setState(275);
					match(TEXT);
					}
					}
					setState(280);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(284);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WHITESPACE) {
					{
					{
					setState(281);
					match(WHITESPACE);
					}
					}
					setState(286);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(287);
				match(NEWLINE);
				}
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class InductorContext extends ParserRuleContext {
		public TerminalNode INDUCTOR_NAME() { return getToken(TParser.INDUCTOR_NAME, 0); }
		public List<TerminalNode> TEXT() { return getTokens(TParser.TEXT); }
		public TerminalNode TEXT(int i) {
			return getToken(TParser.TEXT, i);
		}
		public TerminalNode NEWLINE() { return getToken(TParser.NEWLINE, 0); }
		public List<TerminalNode> WHITESPACE() { return getTokens(TParser.WHITESPACE); }
		public TerminalNode WHITESPACE(int i) {
			return getToken(TParser.WHITESPACE, i);
		}
		public List<TerminalNode> NUMERIC_VALUE() { return getTokens(TParser.NUMERIC_VALUE); }
		public TerminalNode NUMERIC_VALUE(int i) {
			return getToken(TParser.NUMERIC_VALUE, i);
		}
		public List<TerminalNode> PARAMS() { return getTokens(TParser.PARAMS); }
		public TerminalNode PARAMS(int i) {
			return getToken(TParser.PARAMS, i);
		}
		public InductorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_inductor; }
	}

	public final InductorContext inductor() throws RecognitionException {
		InductorContext _localctx = new InductorContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_inductor);
		int _la;
		try {
			int _alt;
			setState(382);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,62,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				{
				setState(290);
				match(INDUCTOR_NAME);
				setState(292); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(291);
					match(WHITESPACE);
					}
					}
					setState(294); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHITESPACE );
				setState(296);
				match(TEXT);
				setState(298); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(297);
					match(WHITESPACE);
					}
					}
					setState(300); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHITESPACE );
				setState(302);
				match(TEXT);
				setState(304); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(303);
					match(WHITESPACE);
					}
					}
					setState(306); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHITESPACE );
				setState(309); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(308);
					match(NUMERIC_VALUE);
					}
					}
					setState(311); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==NUMERIC_VALUE );
				setState(314); 
				_errHandler.sync(this);
				_alt = 1;
				do {
					switch (_alt) {
					case 1:
						{
						{
						setState(313);
						match(WHITESPACE);
						}
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					setState(316); 
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,51,_ctx);
				} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
				setState(321);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==PARAMS) {
					{
					{
					setState(318);
					match(PARAMS);
					}
					}
					setState(323);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(327);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WHITESPACE) {
					{
					{
					setState(324);
					match(WHITESPACE);
					}
					}
					setState(329);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(330);
				match(NEWLINE);
				}
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				{
				setState(331);
				match(INDUCTOR_NAME);
				setState(333); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(332);
					match(WHITESPACE);
					}
					}
					setState(335); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHITESPACE );
				setState(337);
				match(TEXT);
				setState(339); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(338);
					match(WHITESPACE);
					}
					}
					setState(341); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHITESPACE );
				setState(343);
				match(TEXT);
				setState(345); 
				_errHandler.sync(this);
				_alt = 1;
				do {
					switch (_alt) {
					case 1:
						{
						{
						setState(344);
						match(WHITESPACE);
						}
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					setState(347); 
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,56,_ctx);
				} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
				setState(352);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==NUMERIC_VALUE) {
					{
					{
					setState(349);
					match(NUMERIC_VALUE);
					}
					}
					setState(354);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(358);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WHITESPACE) {
					{
					{
					setState(355);
					match(WHITESPACE);
					}
					}
					setState(360);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(361);
				match(NEWLINE);
				}
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				{
				setState(362);
				match(INDUCTOR_NAME);
				setState(364); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(363);
					match(WHITESPACE);
					}
					}
					setState(366); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHITESPACE );
				setState(368);
				match(TEXT);
				setState(370); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(369);
					match(WHITESPACE);
					}
					}
					setState(372); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHITESPACE );
				setState(374);
				match(TEXT);
				setState(378);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WHITESPACE) {
					{
					{
					setState(375);
					match(WHITESPACE);
					}
					}
					setState(380);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(381);
				match(NEWLINE);
				}
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Mutual_inductorContext extends ParserRuleContext {
		public TerminalNode MUTUAL_INDUCTOR_NAME() { return getToken(TParser.MUTUAL_INDUCTOR_NAME, 0); }
		public List<TerminalNode> WHITESPACE() { return getTokens(TParser.WHITESPACE); }
		public TerminalNode WHITESPACE(int i) {
			return getToken(TParser.WHITESPACE, i);
		}
		public List<TerminalNode> INDUCTOR_NAME() { return getTokens(TParser.INDUCTOR_NAME); }
		public TerminalNode INDUCTOR_NAME(int i) {
			return getToken(TParser.INDUCTOR_NAME, i);
		}
		public TerminalNode NUMERIC_VALUE() { return getToken(TParser.NUMERIC_VALUE, 0); }
		public Mutual_inductorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_mutual_inductor; }
	}

	public final Mutual_inductorContext mutual_inductor() throws RecognitionException {
		Mutual_inductorContext _localctx = new Mutual_inductorContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_mutual_inductor);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(384);
			match(MUTUAL_INDUCTOR_NAME);
			setState(385);
			match(WHITESPACE);
			setState(386);
			match(INDUCTOR_NAME);
			setState(387);
			match(WHITESPACE);
			setState(388);
			match(INDUCTOR_NAME);
			setState(389);
			match(WHITESPACE);
			setState(390);
			match(NUMERIC_VALUE);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class DiodContext extends ParserRuleContext {
		public TerminalNode RESISTOR_NAME() { return getToken(TParser.RESISTOR_NAME, 0); }
		public List<TerminalNode> TEXT() { return getTokens(TParser.TEXT); }
		public TerminalNode TEXT(int i) {
			return getToken(TParser.TEXT, i);
		}
		public TerminalNode NEWLINE() { return getToken(TParser.NEWLINE, 0); }
		public List<TerminalNode> WHITESPACE() { return getTokens(TParser.WHITESPACE); }
		public TerminalNode WHITESPACE(int i) {
			return getToken(TParser.WHITESPACE, i);
		}
		public List<TerminalNode> PARAMS() { return getTokens(TParser.PARAMS); }
		public TerminalNode PARAMS(int i) {
			return getToken(TParser.PARAMS, i);
		}
		public DiodContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_diod; }
	}

	public final DiodContext diod() throws RecognitionException {
		DiodContext _localctx = new DiodContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_diod);
		int _la;
		try {
			int _alt;
			setState(484);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,78,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				{
				setState(392);
				match(RESISTOR_NAME);
				setState(394); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(393);
					match(WHITESPACE);
					}
					}
					setState(396); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHITESPACE );
				setState(398);
				match(TEXT);
				setState(400); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(399);
					match(WHITESPACE);
					}
					}
					setState(402); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHITESPACE );
				setState(404);
				match(TEXT);
				setState(406); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(405);
					match(WHITESPACE);
					}
					}
					setState(408); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHITESPACE );
				setState(411); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(410);
					match(TEXT);
					}
					}
					setState(413); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==TEXT );
				setState(416); 
				_errHandler.sync(this);
				_alt = 1;
				do {
					switch (_alt) {
					case 1:
						{
						{
						setState(415);
						match(WHITESPACE);
						}
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					setState(418); 
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,67,_ctx);
				} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
				setState(423);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==PARAMS) {
					{
					{
					setState(420);
					match(PARAMS);
					}
					}
					setState(425);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(429);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WHITESPACE) {
					{
					{
					setState(426);
					match(WHITESPACE);
					}
					}
					setState(431);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(432);
				match(NEWLINE);
				}
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				{
				setState(433);
				match(RESISTOR_NAME);
				setState(435); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(434);
					match(WHITESPACE);
					}
					}
					setState(437); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHITESPACE );
				setState(439);
				match(TEXT);
				setState(441); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(440);
					match(WHITESPACE);
					}
					}
					setState(443); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHITESPACE );
				setState(445);
				match(TEXT);
				setState(447); 
				_errHandler.sync(this);
				_alt = 1;
				do {
					switch (_alt) {
					case 1:
						{
						{
						setState(446);
						match(WHITESPACE);
						}
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					setState(449); 
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,72,_ctx);
				} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
				setState(454);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==TEXT) {
					{
					{
					setState(451);
					match(TEXT);
					}
					}
					setState(456);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(460);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WHITESPACE) {
					{
					{
					setState(457);
					match(WHITESPACE);
					}
					}
					setState(462);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(463);
				match(NEWLINE);
				}
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				{
				setState(464);
				match(RESISTOR_NAME);
				setState(466); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(465);
					match(WHITESPACE);
					}
					}
					setState(468); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHITESPACE );
				setState(470);
				match(TEXT);
				setState(472); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(471);
					match(WHITESPACE);
					}
					}
					setState(474); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHITESPACE );
				setState(476);
				match(TEXT);
				setState(480);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WHITESPACE) {
					{
					{
					setState(477);
					match(WHITESPACE);
					}
					}
					setState(482);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(483);
				match(NEWLINE);
				}
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static final String _serializedATN =
		"\u0004\u0001\u000e\u01e7\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001"+
		"\u0002\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004"+
		"\u0002\u0005\u0007\u0005\u0001\u0000\u0005\u0000\u000e\b\u0000\n\u0000"+
		"\f\u0000\u0011\t\u0000\u0001\u0000\u0005\u0000\u0014\b\u0000\n\u0000\f"+
		"\u0000\u0017\t\u0000\u0001\u0000\u0005\u0000\u001a\b\u0000\n\u0000\f\u0000"+
		"\u001d\t\u0000\u0001\u0001\u0001\u0001\u0004\u0001!\b\u0001\u000b\u0001"+
		"\f\u0001\"\u0001\u0001\u0001\u0001\u0004\u0001\'\b\u0001\u000b\u0001\f"+
		"\u0001(\u0001\u0001\u0001\u0001\u0004\u0001-\b\u0001\u000b\u0001\f\u0001"+
		".\u0001\u0001\u0004\u00012\b\u0001\u000b\u0001\f\u00013\u0001\u0001\u0004"+
		"\u00017\b\u0001\u000b\u0001\f\u00018\u0001\u0001\u0005\u0001<\b\u0001"+
		"\n\u0001\f\u0001?\t\u0001\u0001\u0001\u0005\u0001B\b\u0001\n\u0001\f\u0001"+
		"E\t\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0004\u0001J\b\u0001\u000b"+
		"\u0001\f\u0001K\u0001\u0001\u0001\u0001\u0004\u0001P\b\u0001\u000b\u0001"+
		"\f\u0001Q\u0001\u0001\u0001\u0001\u0004\u0001V\b\u0001\u000b\u0001\f\u0001"+
		"W\u0001\u0001\u0005\u0001[\b\u0001\n\u0001\f\u0001^\t\u0001\u0001\u0001"+
		"\u0005\u0001a\b\u0001\n\u0001\f\u0001d\t\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0004\u0001i\b\u0001\u000b\u0001\f\u0001j\u0001\u0001\u0001"+
		"\u0001\u0004\u0001o\b\u0001\u000b\u0001\f\u0001p\u0001\u0001\u0001\u0001"+
		"\u0005\u0001u\b\u0001\n\u0001\f\u0001x\t\u0001\u0001\u0001\u0003\u0001"+
		"{\b\u0001\u0001\u0002\u0001\u0002\u0004\u0002\u007f\b\u0002\u000b\u0002"+
		"\f\u0002\u0080\u0001\u0002\u0001\u0002\u0004\u0002\u0085\b\u0002\u000b"+
		"\u0002\f\u0002\u0086\u0001\u0002\u0001\u0002\u0004\u0002\u008b\b\u0002"+
		"\u000b\u0002\f\u0002\u008c\u0001\u0002\u0004\u0002\u0090\b\u0002\u000b"+
		"\u0002\f\u0002\u0091\u0001\u0002\u0004\u0002\u0095\b\u0002\u000b\u0002"+
		"\f\u0002\u0096\u0001\u0002\u0005\u0002\u009a\b\u0002\n\u0002\f\u0002\u009d"+
		"\t\u0002\u0001\u0002\u0005\u0002\u00a0\b\u0002\n\u0002\f\u0002\u00a3\t"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0004\u0002\u00a8\b\u0002\u000b"+
		"\u0002\f\u0002\u00a9\u0001\u0002\u0001\u0002\u0004\u0002\u00ae\b\u0002"+
		"\u000b\u0002\f\u0002\u00af\u0001\u0002\u0001\u0002\u0004\u0002\u00b4\b"+
		"\u0002\u000b\u0002\f\u0002\u00b5\u0001\u0002\u0005\u0002\u00b9\b\u0002"+
		"\n\u0002\f\u0002\u00bc\t\u0002\u0001\u0002\u0005\u0002\u00bf\b\u0002\n"+
		"\u0002\f\u0002\u00c2\t\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0004"+
		"\u0002\u00c7\b\u0002\u000b\u0002\f\u0002\u00c8\u0001\u0002\u0001\u0002"+
		"\u0004\u0002\u00cd\b\u0002\u000b\u0002\f\u0002\u00ce\u0001\u0002\u0001"+
		"\u0002\u0005\u0002\u00d3\b\u0002\n\u0002\f\u0002\u00d6\t\u0002\u0001\u0002"+
		"\u0001\u0002\u0001\u0002\u0004\u0002\u00db\b\u0002\u000b\u0002\f\u0002"+
		"\u00dc\u0001\u0002\u0001\u0002\u0004\u0002\u00e1\b\u0002\u000b\u0002\f"+
		"\u0002\u00e2\u0001\u0002\u0001\u0002\u0004\u0002\u00e7\b\u0002\u000b\u0002"+
		"\f\u0002\u00e8\u0001\u0002\u0004\u0002\u00ec\b\u0002\u000b\u0002\f\u0002"+
		"\u00ed\u0001\u0002\u0004\u0002\u00f1\b\u0002\u000b\u0002\f\u0002\u00f2"+
		"\u0001\u0002\u0005\u0002\u00f6\b\u0002\n\u0002\f\u0002\u00f9\t\u0002\u0001"+
		"\u0002\u0005\u0002\u00fc\b\u0002\n\u0002\f\u0002\u00ff\t\u0002\u0001\u0002"+
		"\u0001\u0002\u0001\u0002\u0004\u0002\u0104\b\u0002\u000b\u0002\f\u0002"+
		"\u0105\u0001\u0002\u0001\u0002\u0004\u0002\u010a\b\u0002\u000b\u0002\f"+
		"\u0002\u010b\u0001\u0002\u0001\u0002\u0004\u0002\u0110\b\u0002\u000b\u0002"+
		"\f\u0002\u0111\u0001\u0002\u0005\u0002\u0115\b\u0002\n\u0002\f\u0002\u0118"+
		"\t\u0002\u0001\u0002\u0005\u0002\u011b\b\u0002\n\u0002\f\u0002\u011e\t"+
		"\u0002\u0001\u0002\u0003\u0002\u0121\b\u0002\u0001\u0003\u0001\u0003\u0004"+
		"\u0003\u0125\b\u0003\u000b\u0003\f\u0003\u0126\u0001\u0003\u0001\u0003"+
		"\u0004\u0003\u012b\b\u0003\u000b\u0003\f\u0003\u012c\u0001\u0003\u0001"+
		"\u0003\u0004\u0003\u0131\b\u0003\u000b\u0003\f\u0003\u0132\u0001\u0003"+
		"\u0004\u0003\u0136\b\u0003\u000b\u0003\f\u0003\u0137\u0001\u0003\u0004"+
		"\u0003\u013b\b\u0003\u000b\u0003\f\u0003\u013c\u0001\u0003\u0005\u0003"+
		"\u0140\b\u0003\n\u0003\f\u0003\u0143\t\u0003\u0001\u0003\u0005\u0003\u0146"+
		"\b\u0003\n\u0003\f\u0003\u0149\t\u0003\u0001\u0003\u0001\u0003\u0001\u0003"+
		"\u0004\u0003\u014e\b\u0003\u000b\u0003\f\u0003\u014f\u0001\u0003\u0001"+
		"\u0003\u0004\u0003\u0154\b\u0003\u000b\u0003\f\u0003\u0155\u0001\u0003"+
		"\u0001\u0003\u0004\u0003\u015a\b\u0003\u000b\u0003\f\u0003\u015b\u0001"+
		"\u0003\u0005\u0003\u015f\b\u0003\n\u0003\f\u0003\u0162\t\u0003\u0001\u0003"+
		"\u0005\u0003\u0165\b\u0003\n\u0003\f\u0003\u0168\t\u0003\u0001\u0003\u0001"+
		"\u0003\u0001\u0003\u0004\u0003\u016d\b\u0003\u000b\u0003\f\u0003\u016e"+
		"\u0001\u0003\u0001\u0003\u0004\u0003\u0173\b\u0003\u000b\u0003\f\u0003"+
		"\u0174\u0001\u0003\u0001\u0003\u0005\u0003\u0179\b\u0003\n\u0003\f\u0003"+
		"\u017c\t\u0003\u0001\u0003\u0003\u0003\u017f\b\u0003\u0001\u0004\u0001"+
		"\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001"+
		"\u0004\u0001\u0005\u0001\u0005\u0004\u0005\u018b\b\u0005\u000b\u0005\f"+
		"\u0005\u018c\u0001\u0005\u0001\u0005\u0004\u0005\u0191\b\u0005\u000b\u0005"+
		"\f\u0005\u0192\u0001\u0005\u0001\u0005\u0004\u0005\u0197\b\u0005\u000b"+
		"\u0005\f\u0005\u0198\u0001\u0005\u0004\u0005\u019c\b\u0005\u000b\u0005"+
		"\f\u0005\u019d\u0001\u0005\u0004\u0005\u01a1\b\u0005\u000b\u0005\f\u0005"+
		"\u01a2\u0001\u0005\u0005\u0005\u01a6\b\u0005\n\u0005\f\u0005\u01a9\t\u0005"+
		"\u0001\u0005\u0005\u0005\u01ac\b\u0005\n\u0005\f\u0005\u01af\t\u0005\u0001"+
		"\u0005\u0001\u0005\u0001\u0005\u0004\u0005\u01b4\b\u0005\u000b\u0005\f"+
		"\u0005\u01b5\u0001\u0005\u0001\u0005\u0004\u0005\u01ba\b\u0005\u000b\u0005"+
		"\f\u0005\u01bb\u0001\u0005\u0001\u0005\u0004\u0005\u01c0\b\u0005\u000b"+
		"\u0005\f\u0005\u01c1\u0001\u0005\u0005\u0005\u01c5\b\u0005\n\u0005\f\u0005"+
		"\u01c8\t\u0005\u0001\u0005\u0005\u0005\u01cb\b\u0005\n\u0005\f\u0005\u01ce"+
		"\t\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0004\u0005\u01d3\b\u0005"+
		"\u000b\u0005\f\u0005\u01d4\u0001\u0005\u0001\u0005\u0004\u0005\u01d9\b"+
		"\u0005\u000b\u0005\f\u0005\u01da\u0001\u0005\u0001\u0005\u0005\u0005\u01df"+
		"\b\u0005\n\u0005\f\u0005\u01e2\t\u0005\u0001\u0005\u0003\u0005\u01e5\b"+
		"\u0005\u0001\u0005\u0000\u0000\u0006\u0000\u0002\u0004\u0006\b\n\u0000"+
		"\u0000\u0235\u0000\u000f\u0001\u0000\u0000\u0000\u0002z\u0001\u0000\u0000"+
		"\u0000\u0004\u0120\u0001\u0000\u0000\u0000\u0006\u017e\u0001\u0000\u0000"+
		"\u0000\b\u0180\u0001\u0000\u0000\u0000\n\u01e4\u0001\u0000\u0000\u0000"+
		"\f\u000e\u0003\u0002\u0001\u0000\r\f\u0001\u0000\u0000\u0000\u000e\u0011"+
		"\u0001\u0000\u0000\u0000\u000f\r\u0001\u0000\u0000\u0000\u000f\u0010\u0001"+
		"\u0000\u0000\u0000\u0010\u0015\u0001\u0000\u0000\u0000\u0011\u000f\u0001"+
		"\u0000\u0000\u0000\u0012\u0014\u0003\u0004\u0002\u0000\u0013\u0012\u0001"+
		"\u0000\u0000\u0000\u0014\u0017\u0001\u0000\u0000\u0000\u0015\u0013\u0001"+
		"\u0000\u0000\u0000\u0015\u0016\u0001\u0000\u0000\u0000\u0016\u001b\u0001"+
		"\u0000\u0000\u0000\u0017\u0015\u0001\u0000\u0000\u0000\u0018\u001a\u0003"+
		"\u0006\u0003\u0000\u0019\u0018\u0001\u0000\u0000\u0000\u001a\u001d\u0001"+
		"\u0000\u0000\u0000\u001b\u0019\u0001\u0000\u0000\u0000\u001b\u001c\u0001"+
		"\u0000\u0000\u0000\u001c\u0001\u0001\u0000\u0000\u0000\u001d\u001b\u0001"+
		"\u0000\u0000\u0000\u001e \u0005\u0004\u0000\u0000\u001f!\u0005\u0002\u0000"+
		"\u0000 \u001f\u0001\u0000\u0000\u0000!\"\u0001\u0000\u0000\u0000\" \u0001"+
		"\u0000\u0000\u0000\"#\u0001\u0000\u0000\u0000#$\u0001\u0000\u0000\u0000"+
		"$&\u0005\u000e\u0000\u0000%\'\u0005\u0002\u0000\u0000&%\u0001\u0000\u0000"+
		"\u0000\'(\u0001\u0000\u0000\u0000(&\u0001\u0000\u0000\u0000()\u0001\u0000"+
		"\u0000\u0000)*\u0001\u0000\u0000\u0000*,\u0005\u000e\u0000\u0000+-\u0005"+
		"\u0002\u0000\u0000,+\u0001\u0000\u0000\u0000-.\u0001\u0000\u0000\u0000"+
		".,\u0001\u0000\u0000\u0000./\u0001\u0000\u0000\u0000/1\u0001\u0000\u0000"+
		"\u000002\u0005\n\u0000\u000010\u0001\u0000\u0000\u000023\u0001\u0000\u0000"+
		"\u000031\u0001\u0000\u0000\u000034\u0001\u0000\u0000\u000046\u0001\u0000"+
		"\u0000\u000057\u0005\u0002\u0000\u000065\u0001\u0000\u0000\u000078\u0001"+
		"\u0000\u0000\u000086\u0001\u0000\u0000\u000089\u0001\u0000\u0000\u0000"+
		"9=\u0001\u0000\u0000\u0000:<\u0005\r\u0000\u0000;:\u0001\u0000\u0000\u0000"+
		"<?\u0001\u0000\u0000\u0000=;\u0001\u0000\u0000\u0000=>\u0001\u0000\u0000"+
		"\u0000>C\u0001\u0000\u0000\u0000?=\u0001\u0000\u0000\u0000@B\u0005\u0002"+
		"\u0000\u0000A@\u0001\u0000\u0000\u0000BE\u0001\u0000\u0000\u0000CA\u0001"+
		"\u0000\u0000\u0000CD\u0001\u0000\u0000\u0000DF\u0001\u0000\u0000\u0000"+
		"EC\u0001\u0000\u0000\u0000F{\u0005\u0003\u0000\u0000GI\u0005\u0004\u0000"+
		"\u0000HJ\u0005\u0002\u0000\u0000IH\u0001\u0000\u0000\u0000JK\u0001\u0000"+
		"\u0000\u0000KI\u0001\u0000\u0000\u0000KL\u0001\u0000\u0000\u0000LM\u0001"+
		"\u0000\u0000\u0000MO\u0005\u000e\u0000\u0000NP\u0005\u0002\u0000\u0000"+
		"ON\u0001\u0000\u0000\u0000PQ\u0001\u0000\u0000\u0000QO\u0001\u0000\u0000"+
		"\u0000QR\u0001\u0000\u0000\u0000RS\u0001\u0000\u0000\u0000SU\u0005\u000e"+
		"\u0000\u0000TV\u0005\u0002\u0000\u0000UT\u0001\u0000\u0000\u0000VW\u0001"+
		"\u0000\u0000\u0000WU\u0001\u0000\u0000\u0000WX\u0001\u0000\u0000\u0000"+
		"X\\\u0001\u0000\u0000\u0000Y[\u0005\n\u0000\u0000ZY\u0001\u0000\u0000"+
		"\u0000[^\u0001\u0000\u0000\u0000\\Z\u0001\u0000\u0000\u0000\\]\u0001\u0000"+
		"\u0000\u0000]b\u0001\u0000\u0000\u0000^\\\u0001\u0000\u0000\u0000_a\u0005"+
		"\u0002\u0000\u0000`_\u0001\u0000\u0000\u0000ad\u0001\u0000\u0000\u0000"+
		"b`\u0001\u0000\u0000\u0000bc\u0001\u0000\u0000\u0000ce\u0001\u0000\u0000"+
		"\u0000db\u0001\u0000\u0000\u0000e{\u0005\u0003\u0000\u0000fh\u0005\u0004"+
		"\u0000\u0000gi\u0005\u0002\u0000\u0000hg\u0001\u0000\u0000\u0000ij\u0001"+
		"\u0000\u0000\u0000jh\u0001\u0000\u0000\u0000jk\u0001\u0000\u0000\u0000"+
		"kl\u0001\u0000\u0000\u0000ln\u0005\u000e\u0000\u0000mo\u0005\u0002\u0000"+
		"\u0000nm\u0001\u0000\u0000\u0000op\u0001\u0000\u0000\u0000pn\u0001\u0000"+
		"\u0000\u0000pq\u0001\u0000\u0000\u0000qr\u0001\u0000\u0000\u0000rv\u0005"+
		"\u000e\u0000\u0000su\u0005\u0002\u0000\u0000ts\u0001\u0000\u0000\u0000"+
		"ux\u0001\u0000\u0000\u0000vt\u0001\u0000\u0000\u0000vw\u0001\u0000\u0000"+
		"\u0000wy\u0001\u0000\u0000\u0000xv\u0001\u0000\u0000\u0000y{\u0005\u0003"+
		"\u0000\u0000z\u001e\u0001\u0000\u0000\u0000zG\u0001\u0000\u0000\u0000"+
		"zf\u0001\u0000\u0000\u0000{\u0003\u0001\u0000\u0000\u0000|~\u0005\u0005"+
		"\u0000\u0000}\u007f\u0005\u0002\u0000\u0000~}\u0001\u0000\u0000\u0000"+
		"\u007f\u0080\u0001\u0000\u0000\u0000\u0080~\u0001\u0000\u0000\u0000\u0080"+
		"\u0081\u0001\u0000\u0000\u0000\u0081\u0082\u0001\u0000\u0000\u0000\u0082"+
		"\u0084\u0005\u000e\u0000\u0000\u0083\u0085\u0005\u0002\u0000\u0000\u0084"+
		"\u0083\u0001\u0000\u0000\u0000\u0085\u0086\u0001\u0000\u0000\u0000\u0086"+
		"\u0084\u0001\u0000\u0000\u0000\u0086\u0087\u0001\u0000\u0000\u0000\u0087"+
		"\u0088\u0001\u0000\u0000\u0000\u0088\u008a\u0005\u000e\u0000\u0000\u0089"+
		"\u008b\u0005\u0002\u0000\u0000\u008a\u0089\u0001\u0000\u0000\u0000\u008b"+
		"\u008c\u0001\u0000\u0000\u0000\u008c\u008a\u0001\u0000\u0000\u0000\u008c"+
		"\u008d\u0001\u0000\u0000\u0000\u008d\u008f\u0001\u0000\u0000\u0000\u008e"+
		"\u0090\u0005\n\u0000\u0000\u008f\u008e\u0001\u0000\u0000\u0000\u0090\u0091"+
		"\u0001\u0000\u0000\u0000\u0091\u008f\u0001\u0000\u0000\u0000\u0091\u0092"+
		"\u0001\u0000\u0000\u0000\u0092\u0094\u0001\u0000\u0000\u0000\u0093\u0095"+
		"\u0005\u0002\u0000\u0000\u0094\u0093\u0001\u0000\u0000\u0000\u0095\u0096"+
		"\u0001\u0000\u0000\u0000\u0096\u0094\u0001\u0000\u0000\u0000\u0096\u0097"+
		"\u0001\u0000\u0000\u0000\u0097\u009b\u0001\u0000\u0000\u0000\u0098\u009a"+
		"\u0005\r\u0000\u0000\u0099\u0098\u0001\u0000\u0000\u0000\u009a\u009d\u0001"+
		"\u0000\u0000\u0000\u009b\u0099\u0001\u0000\u0000\u0000\u009b\u009c\u0001"+
		"\u0000\u0000\u0000\u009c\u00a1\u0001\u0000\u0000\u0000\u009d\u009b\u0001"+
		"\u0000\u0000\u0000\u009e\u00a0\u0005\u0002\u0000\u0000\u009f\u009e\u0001"+
		"\u0000\u0000\u0000\u00a0\u00a3\u0001\u0000\u0000\u0000\u00a1\u009f\u0001"+
		"\u0000\u0000\u0000\u00a1\u00a2\u0001\u0000\u0000\u0000\u00a2\u00a4\u0001"+
		"\u0000\u0000\u0000\u00a3\u00a1\u0001\u0000\u0000\u0000\u00a4\u0121\u0005"+
		"\u0003\u0000\u0000\u00a5\u00a7\u0005\u0005\u0000\u0000\u00a6\u00a8\u0005"+
		"\u0002\u0000\u0000\u00a7\u00a6\u0001\u0000\u0000\u0000\u00a8\u00a9\u0001"+
		"\u0000\u0000\u0000\u00a9\u00a7\u0001\u0000\u0000\u0000\u00a9\u00aa\u0001"+
		"\u0000\u0000\u0000\u00aa\u00ab\u0001\u0000\u0000\u0000\u00ab\u00ad\u0005"+
		"\u000e\u0000\u0000\u00ac\u00ae\u0005\u0002\u0000\u0000\u00ad\u00ac\u0001"+
		"\u0000\u0000\u0000\u00ae\u00af\u0001\u0000\u0000\u0000\u00af\u00ad\u0001"+
		"\u0000\u0000\u0000\u00af\u00b0\u0001\u0000\u0000\u0000\u00b0\u00b1\u0001"+
		"\u0000\u0000\u0000\u00b1\u00b3\u0005\u000e\u0000\u0000\u00b2\u00b4\u0005"+
		"\u0002\u0000\u0000\u00b3\u00b2\u0001\u0000\u0000\u0000\u00b4\u00b5\u0001"+
		"\u0000\u0000\u0000\u00b5\u00b3\u0001\u0000\u0000\u0000\u00b5\u00b6\u0001"+
		"\u0000\u0000\u0000\u00b6\u00ba\u0001\u0000\u0000\u0000\u00b7\u00b9\u0005"+
		"\n\u0000\u0000\u00b8\u00b7\u0001\u0000\u0000\u0000\u00b9\u00bc\u0001\u0000"+
		"\u0000\u0000\u00ba\u00b8\u0001\u0000\u0000\u0000\u00ba\u00bb\u0001\u0000"+
		"\u0000\u0000\u00bb\u00c0\u0001\u0000\u0000\u0000\u00bc\u00ba\u0001\u0000"+
		"\u0000\u0000\u00bd\u00bf\u0005\u0002\u0000\u0000\u00be\u00bd\u0001\u0000"+
		"\u0000\u0000\u00bf\u00c2\u0001\u0000\u0000\u0000\u00c0\u00be\u0001\u0000"+
		"\u0000\u0000\u00c0\u00c1\u0001\u0000\u0000\u0000\u00c1\u00c3\u0001\u0000"+
		"\u0000\u0000\u00c2\u00c0\u0001\u0000\u0000\u0000\u00c3\u0121\u0005\u0003"+
		"\u0000\u0000\u00c4\u00c6\u0005\u0005\u0000\u0000\u00c5\u00c7\u0005\u0002"+
		"\u0000\u0000\u00c6\u00c5\u0001\u0000\u0000\u0000\u00c7\u00c8\u0001\u0000"+
		"\u0000\u0000\u00c8\u00c6\u0001\u0000\u0000\u0000\u00c8\u00c9\u0001\u0000"+
		"\u0000\u0000\u00c9\u00ca\u0001\u0000\u0000\u0000\u00ca\u00cc\u0005\u000e"+
		"\u0000\u0000\u00cb\u00cd\u0005\u0002\u0000\u0000\u00cc\u00cb\u0001\u0000"+
		"\u0000\u0000\u00cd\u00ce\u0001\u0000\u0000\u0000\u00ce\u00cc\u0001\u0000"+
		"\u0000\u0000\u00ce\u00cf\u0001\u0000\u0000\u0000\u00cf\u00d0\u0001\u0000"+
		"\u0000\u0000\u00d0\u00d4\u0005\u000e\u0000\u0000\u00d1\u00d3\u0005\u0002"+
		"\u0000\u0000\u00d2\u00d1\u0001\u0000\u0000\u0000\u00d3\u00d6\u0001\u0000"+
		"\u0000\u0000\u00d4\u00d2\u0001\u0000\u0000\u0000\u00d4\u00d5\u0001\u0000"+
		"\u0000\u0000\u00d5\u00d7\u0001\u0000\u0000\u0000\u00d6\u00d4\u0001\u0000"+
		"\u0000\u0000\u00d7\u0121\u0005\u0003\u0000\u0000\u00d8\u00da\u0005\u0005"+
		"\u0000\u0000\u00d9\u00db\u0005\u0002\u0000\u0000\u00da\u00d9\u0001\u0000"+
		"\u0000\u0000\u00db\u00dc\u0001\u0000\u0000\u0000\u00dc\u00da\u0001\u0000"+
		"\u0000\u0000\u00dc\u00dd\u0001\u0000\u0000\u0000\u00dd\u00de\u0001\u0000"+
		"\u0000\u0000\u00de\u00e0\u0005\u000e\u0000\u0000\u00df\u00e1\u0005\u0002"+
		"\u0000\u0000\u00e0\u00df\u0001\u0000\u0000\u0000\u00e1\u00e2\u0001\u0000"+
		"\u0000\u0000\u00e2\u00e0\u0001\u0000\u0000\u0000\u00e2\u00e3\u0001\u0000"+
		"\u0000\u0000\u00e3\u00e4\u0001\u0000\u0000\u0000\u00e4\u00e6\u0005\u000e"+
		"\u0000\u0000\u00e5\u00e7\u0005\u0002\u0000\u0000\u00e6\u00e5\u0001\u0000"+
		"\u0000\u0000\u00e7\u00e8\u0001\u0000\u0000\u0000\u00e8\u00e6\u0001\u0000"+
		"\u0000\u0000\u00e8\u00e9\u0001\u0000\u0000\u0000\u00e9\u00eb\u0001\u0000"+
		"\u0000\u0000\u00ea\u00ec\u0005\u000e\u0000\u0000\u00eb\u00ea\u0001\u0000"+
		"\u0000\u0000\u00ec\u00ed\u0001\u0000\u0000\u0000\u00ed\u00eb\u0001\u0000"+
		"\u0000\u0000\u00ed\u00ee\u0001\u0000\u0000\u0000\u00ee\u00f0\u0001\u0000"+
		"\u0000\u0000\u00ef\u00f1\u0005\u0002\u0000\u0000\u00f0\u00ef\u0001\u0000"+
		"\u0000\u0000\u00f1\u00f2\u0001\u0000\u0000\u0000\u00f2\u00f0\u0001\u0000"+
		"\u0000\u0000\u00f2\u00f3\u0001\u0000\u0000\u0000\u00f3\u00f7\u0001\u0000"+
		"\u0000\u0000\u00f4\u00f6\u0005\r\u0000\u0000\u00f5\u00f4\u0001\u0000\u0000"+
		"\u0000\u00f6\u00f9\u0001\u0000\u0000\u0000\u00f7\u00f5\u0001\u0000\u0000"+
		"\u0000\u00f7\u00f8\u0001\u0000\u0000\u0000\u00f8\u00fd\u0001\u0000\u0000"+
		"\u0000\u00f9\u00f7\u0001\u0000\u0000\u0000\u00fa\u00fc\u0005\u0002\u0000"+
		"\u0000\u00fb\u00fa\u0001\u0000\u0000\u0000\u00fc\u00ff\u0001\u0000\u0000"+
		"\u0000\u00fd\u00fb\u0001\u0000\u0000\u0000\u00fd\u00fe\u0001\u0000\u0000"+
		"\u0000\u00fe\u0100\u0001\u0000\u0000\u0000\u00ff\u00fd\u0001\u0000\u0000"+
		"\u0000\u0100\u0121\u0005\u0003\u0000\u0000\u0101\u0103\u0005\u0005\u0000"+
		"\u0000\u0102\u0104\u0005\u0002\u0000\u0000\u0103\u0102\u0001\u0000\u0000"+
		"\u0000\u0104\u0105\u0001\u0000\u0000\u0000\u0105\u0103\u0001\u0000\u0000"+
		"\u0000\u0105\u0106\u0001\u0000\u0000\u0000\u0106\u0107\u0001\u0000\u0000"+
		"\u0000\u0107\u0109\u0005\u000e\u0000\u0000\u0108\u010a\u0005\u0002\u0000"+
		"\u0000\u0109\u0108\u0001\u0000\u0000\u0000\u010a\u010b\u0001\u0000\u0000"+
		"\u0000\u010b\u0109\u0001\u0000\u0000\u0000\u010b\u010c\u0001\u0000\u0000"+
		"\u0000\u010c\u010d\u0001\u0000\u0000\u0000\u010d\u010f\u0005\u000e\u0000"+
		"\u0000\u010e\u0110\u0005\u0002\u0000\u0000\u010f\u010e\u0001\u0000\u0000"+
		"\u0000\u0110\u0111\u0001\u0000\u0000\u0000\u0111\u010f\u0001\u0000\u0000"+
		"\u0000\u0111\u0112\u0001\u0000\u0000\u0000\u0112\u0116\u0001\u0000\u0000"+
		"\u0000\u0113\u0115\u0005\u000e\u0000\u0000\u0114\u0113\u0001\u0000\u0000"+
		"\u0000\u0115\u0118\u0001\u0000\u0000\u0000\u0116\u0114\u0001\u0000\u0000"+
		"\u0000\u0116\u0117\u0001\u0000\u0000\u0000\u0117\u011c\u0001\u0000\u0000"+
		"\u0000\u0118\u0116\u0001\u0000\u0000\u0000\u0119\u011b\u0005\u0002\u0000"+
		"\u0000\u011a\u0119\u0001\u0000\u0000\u0000\u011b\u011e\u0001\u0000\u0000"+
		"\u0000\u011c\u011a\u0001\u0000\u0000\u0000\u011c\u011d\u0001\u0000\u0000"+
		"\u0000\u011d\u011f\u0001\u0000\u0000\u0000\u011e\u011c\u0001\u0000\u0000"+
		"\u0000\u011f\u0121\u0005\u0003\u0000\u0000\u0120|\u0001\u0000\u0000\u0000"+
		"\u0120\u00a5\u0001\u0000\u0000\u0000\u0120\u00c4\u0001\u0000\u0000\u0000"+
		"\u0120\u00d8\u0001\u0000\u0000\u0000\u0120\u0101\u0001\u0000\u0000\u0000"+
		"\u0121\u0005\u0001\u0000\u0000\u0000\u0122\u0124\u0005\u0006\u0000\u0000"+
		"\u0123\u0125\u0005\u0002\u0000\u0000\u0124\u0123\u0001\u0000\u0000\u0000"+
		"\u0125\u0126\u0001\u0000\u0000\u0000\u0126\u0124\u0001\u0000\u0000\u0000"+
		"\u0126\u0127\u0001\u0000\u0000\u0000\u0127\u0128\u0001\u0000\u0000\u0000"+
		"\u0128\u012a\u0005\u000e\u0000\u0000\u0129\u012b\u0005\u0002\u0000\u0000"+
		"\u012a\u0129\u0001\u0000\u0000\u0000\u012b\u012c\u0001\u0000\u0000\u0000"+
		"\u012c\u012a\u0001\u0000\u0000\u0000\u012c\u012d\u0001\u0000\u0000\u0000"+
		"\u012d\u012e\u0001\u0000\u0000\u0000\u012e\u0130\u0005\u000e\u0000\u0000"+
		"\u012f\u0131\u0005\u0002\u0000\u0000\u0130\u012f\u0001\u0000\u0000\u0000"+
		"\u0131\u0132\u0001\u0000\u0000\u0000\u0132\u0130\u0001\u0000\u0000\u0000"+
		"\u0132\u0133\u0001\u0000\u0000\u0000\u0133\u0135\u0001\u0000\u0000\u0000"+
		"\u0134\u0136\u0005\n\u0000\u0000\u0135\u0134\u0001\u0000\u0000\u0000\u0136"+
		"\u0137\u0001\u0000\u0000\u0000\u0137\u0135\u0001\u0000\u0000\u0000\u0137"+
		"\u0138\u0001\u0000\u0000\u0000\u0138\u013a\u0001\u0000\u0000\u0000\u0139"+
		"\u013b\u0005\u0002\u0000\u0000\u013a\u0139\u0001\u0000\u0000\u0000\u013b"+
		"\u013c\u0001\u0000\u0000\u0000\u013c\u013a\u0001\u0000\u0000\u0000\u013c"+
		"\u013d\u0001\u0000\u0000\u0000\u013d\u0141\u0001\u0000\u0000\u0000\u013e"+
		"\u0140\u0005\r\u0000\u0000\u013f\u013e\u0001\u0000\u0000\u0000\u0140\u0143"+
		"\u0001\u0000\u0000\u0000\u0141\u013f\u0001\u0000\u0000\u0000\u0141\u0142"+
		"\u0001\u0000\u0000\u0000\u0142\u0147\u0001\u0000\u0000\u0000\u0143\u0141"+
		"\u0001\u0000\u0000\u0000\u0144\u0146\u0005\u0002\u0000\u0000\u0145\u0144"+
		"\u0001\u0000\u0000\u0000\u0146\u0149\u0001\u0000\u0000\u0000\u0147\u0145"+
		"\u0001\u0000\u0000\u0000\u0147\u0148\u0001\u0000\u0000\u0000\u0148\u014a"+
		"\u0001\u0000\u0000\u0000\u0149\u0147\u0001\u0000\u0000\u0000\u014a\u017f"+
		"\u0005\u0003\u0000\u0000\u014b\u014d\u0005\u0006\u0000\u0000\u014c\u014e"+
		"\u0005\u0002\u0000\u0000\u014d\u014c\u0001\u0000\u0000\u0000\u014e\u014f"+
		"\u0001\u0000\u0000\u0000\u014f\u014d\u0001\u0000\u0000\u0000\u014f\u0150"+
		"\u0001\u0000\u0000\u0000\u0150\u0151\u0001\u0000\u0000\u0000\u0151\u0153"+
		"\u0005\u000e\u0000\u0000\u0152\u0154\u0005\u0002\u0000\u0000\u0153\u0152"+
		"\u0001\u0000\u0000\u0000\u0154\u0155\u0001\u0000\u0000\u0000\u0155\u0153"+
		"\u0001\u0000\u0000\u0000\u0155\u0156\u0001\u0000\u0000\u0000\u0156\u0157"+
		"\u0001\u0000\u0000\u0000\u0157\u0159\u0005\u000e\u0000\u0000\u0158\u015a"+
		"\u0005\u0002\u0000\u0000\u0159\u0158\u0001\u0000\u0000\u0000\u015a\u015b"+
		"\u0001\u0000\u0000\u0000\u015b\u0159\u0001\u0000\u0000\u0000\u015b\u015c"+
		"\u0001\u0000\u0000\u0000\u015c\u0160\u0001\u0000\u0000\u0000\u015d\u015f"+
		"\u0005\n\u0000\u0000\u015e\u015d\u0001\u0000\u0000\u0000\u015f\u0162\u0001"+
		"\u0000\u0000\u0000\u0160\u015e\u0001\u0000\u0000\u0000\u0160\u0161\u0001"+
		"\u0000\u0000\u0000\u0161\u0166\u0001\u0000\u0000\u0000\u0162\u0160\u0001"+
		"\u0000\u0000\u0000\u0163\u0165\u0005\u0002\u0000\u0000\u0164\u0163\u0001"+
		"\u0000\u0000\u0000\u0165\u0168\u0001\u0000\u0000\u0000\u0166\u0164\u0001"+
		"\u0000\u0000\u0000\u0166\u0167\u0001\u0000\u0000\u0000\u0167\u0169\u0001"+
		"\u0000\u0000\u0000\u0168\u0166\u0001\u0000\u0000\u0000\u0169\u017f\u0005"+
		"\u0003\u0000\u0000\u016a\u016c\u0005\u0006\u0000\u0000\u016b\u016d\u0005"+
		"\u0002\u0000\u0000\u016c\u016b\u0001\u0000\u0000\u0000\u016d\u016e\u0001"+
		"\u0000\u0000\u0000\u016e\u016c\u0001\u0000\u0000\u0000\u016e\u016f\u0001"+
		"\u0000\u0000\u0000\u016f\u0170\u0001\u0000\u0000\u0000\u0170\u0172\u0005"+
		"\u000e\u0000\u0000\u0171\u0173\u0005\u0002\u0000\u0000\u0172\u0171\u0001"+
		"\u0000\u0000\u0000\u0173\u0174\u0001\u0000\u0000\u0000\u0174\u0172\u0001"+
		"\u0000\u0000\u0000\u0174\u0175\u0001\u0000\u0000\u0000\u0175\u0176\u0001"+
		"\u0000\u0000\u0000\u0176\u017a\u0005\u000e\u0000\u0000\u0177\u0179\u0005"+
		"\u0002\u0000\u0000\u0178\u0177\u0001\u0000\u0000\u0000\u0179\u017c\u0001"+
		"\u0000\u0000\u0000\u017a\u0178\u0001\u0000\u0000\u0000\u017a\u017b\u0001"+
		"\u0000\u0000\u0000\u017b\u017d\u0001\u0000\u0000\u0000\u017c\u017a\u0001"+
		"\u0000\u0000\u0000\u017d\u017f\u0005\u0003\u0000\u0000\u017e\u0122\u0001"+
		"\u0000\u0000\u0000\u017e\u014b\u0001\u0000\u0000\u0000\u017e\u016a\u0001"+
		"\u0000\u0000\u0000\u017f\u0007\u0001\u0000\u0000\u0000\u0180\u0181\u0005"+
		"\u0007\u0000\u0000\u0181\u0182\u0005\u0002\u0000\u0000\u0182\u0183\u0005"+
		"\u0006\u0000\u0000\u0183\u0184\u0005\u0002\u0000\u0000\u0184\u0185\u0005"+
		"\u0006\u0000\u0000\u0185\u0186\u0005\u0002\u0000\u0000\u0186\u0187\u0005"+
		"\n\u0000\u0000\u0187\t\u0001\u0000\u0000\u0000\u0188\u018a\u0005\u0004"+
		"\u0000\u0000\u0189\u018b\u0005\u0002\u0000\u0000\u018a\u0189\u0001\u0000"+
		"\u0000\u0000\u018b\u018c\u0001\u0000\u0000\u0000\u018c\u018a\u0001\u0000"+
		"\u0000\u0000\u018c\u018d\u0001\u0000\u0000\u0000\u018d\u018e\u0001\u0000"+
		"\u0000\u0000\u018e\u0190\u0005\u000e\u0000\u0000\u018f\u0191\u0005\u0002"+
		"\u0000\u0000\u0190\u018f\u0001\u0000\u0000\u0000\u0191\u0192\u0001\u0000"+
		"\u0000\u0000\u0192\u0190\u0001\u0000\u0000\u0000\u0192\u0193\u0001\u0000"+
		"\u0000\u0000\u0193\u0194\u0001\u0000\u0000\u0000\u0194\u0196\u0005\u000e"+
		"\u0000\u0000\u0195\u0197\u0005\u0002\u0000\u0000\u0196\u0195\u0001\u0000"+
		"\u0000\u0000\u0197\u0198\u0001\u0000\u0000\u0000\u0198\u0196\u0001\u0000"+
		"\u0000\u0000\u0198\u0199\u0001\u0000\u0000\u0000\u0199\u019b\u0001\u0000"+
		"\u0000\u0000\u019a\u019c\u0005\u000e\u0000\u0000\u019b\u019a\u0001\u0000"+
		"\u0000\u0000\u019c\u019d\u0001\u0000\u0000\u0000\u019d\u019b\u0001\u0000"+
		"\u0000\u0000\u019d\u019e\u0001\u0000\u0000\u0000\u019e\u01a0\u0001\u0000"+
		"\u0000\u0000\u019f\u01a1\u0005\u0002\u0000\u0000\u01a0\u019f\u0001\u0000"+
		"\u0000\u0000\u01a1\u01a2\u0001\u0000\u0000\u0000\u01a2\u01a0\u0001\u0000"+
		"\u0000\u0000\u01a2\u01a3\u0001\u0000\u0000\u0000\u01a3\u01a7\u0001\u0000"+
		"\u0000\u0000\u01a4\u01a6\u0005\r\u0000\u0000\u01a5\u01a4\u0001\u0000\u0000"+
		"\u0000\u01a6\u01a9\u0001\u0000\u0000\u0000\u01a7\u01a5\u0001\u0000\u0000"+
		"\u0000\u01a7\u01a8\u0001\u0000\u0000\u0000\u01a8\u01ad\u0001\u0000\u0000"+
		"\u0000\u01a9\u01a7\u0001\u0000\u0000\u0000\u01aa\u01ac\u0005\u0002\u0000"+
		"\u0000\u01ab\u01aa\u0001\u0000\u0000\u0000\u01ac\u01af\u0001\u0000\u0000"+
		"\u0000\u01ad\u01ab\u0001\u0000\u0000\u0000\u01ad\u01ae\u0001\u0000\u0000"+
		"\u0000\u01ae\u01b0\u0001\u0000\u0000\u0000\u01af\u01ad\u0001\u0000\u0000"+
		"\u0000\u01b0\u01e5\u0005\u0003\u0000\u0000\u01b1\u01b3\u0005\u0004\u0000"+
		"\u0000\u01b2\u01b4\u0005\u0002\u0000\u0000\u01b3\u01b2\u0001\u0000\u0000"+
		"\u0000\u01b4\u01b5\u0001\u0000\u0000\u0000\u01b5\u01b3\u0001\u0000\u0000"+
		"\u0000\u01b5\u01b6\u0001\u0000\u0000\u0000\u01b6\u01b7\u0001\u0000\u0000"+
		"\u0000\u01b7\u01b9\u0005\u000e\u0000\u0000\u01b8\u01ba\u0005\u0002\u0000"+
		"\u0000\u01b9\u01b8\u0001\u0000\u0000\u0000\u01ba\u01bb\u0001\u0000\u0000"+
		"\u0000\u01bb\u01b9\u0001\u0000\u0000\u0000\u01bb\u01bc\u0001\u0000\u0000"+
		"\u0000\u01bc\u01bd\u0001\u0000\u0000\u0000\u01bd\u01bf\u0005\u000e\u0000"+
		"\u0000\u01be\u01c0\u0005\u0002\u0000\u0000\u01bf\u01be\u0001\u0000\u0000"+
		"\u0000\u01c0\u01c1\u0001\u0000\u0000\u0000\u01c1\u01bf\u0001\u0000\u0000"+
		"\u0000\u01c1\u01c2\u0001\u0000\u0000\u0000\u01c2\u01c6\u0001\u0000\u0000"+
		"\u0000\u01c3\u01c5\u0005\u000e\u0000\u0000\u01c4\u01c3\u0001\u0000\u0000"+
		"\u0000\u01c5\u01c8\u0001\u0000\u0000\u0000\u01c6\u01c4\u0001\u0000\u0000"+
		"\u0000\u01c6\u01c7\u0001\u0000\u0000\u0000\u01c7\u01cc\u0001\u0000\u0000"+
		"\u0000\u01c8\u01c6\u0001\u0000\u0000\u0000\u01c9\u01cb\u0005\u0002\u0000"+
		"\u0000\u01ca\u01c9\u0001\u0000\u0000\u0000\u01cb\u01ce\u0001\u0000\u0000"+
		"\u0000\u01cc\u01ca\u0001\u0000\u0000\u0000\u01cc\u01cd\u0001\u0000\u0000"+
		"\u0000\u01cd\u01cf\u0001\u0000\u0000\u0000\u01ce\u01cc\u0001\u0000\u0000"+
		"\u0000\u01cf\u01e5\u0005\u0003\u0000\u0000\u01d0\u01d2\u0005\u0004\u0000"+
		"\u0000\u01d1\u01d3\u0005\u0002\u0000\u0000\u01d2\u01d1\u0001\u0000\u0000"+
		"\u0000\u01d3\u01d4\u0001\u0000\u0000\u0000\u01d4\u01d2\u0001\u0000\u0000"+
		"\u0000\u01d4\u01d5\u0001\u0000\u0000\u0000\u01d5\u01d6\u0001\u0000\u0000"+
		"\u0000\u01d6\u01d8\u0005\u000e\u0000\u0000\u01d7\u01d9\u0005\u0002\u0000"+
		"\u0000\u01d8\u01d7\u0001\u0000\u0000\u0000\u01d9\u01da\u0001\u0000\u0000"+
		"\u0000\u01da\u01d8\u0001\u0000\u0000\u0000\u01da\u01db\u0001\u0000\u0000"+
		"\u0000\u01db\u01dc\u0001\u0000\u0000\u0000\u01dc\u01e0\u0005\u000e\u0000"+
		"\u0000\u01dd\u01df\u0005\u0002\u0000\u0000\u01de\u01dd\u0001\u0000\u0000"+
		"\u0000\u01df\u01e2\u0001\u0000\u0000\u0000\u01e0\u01de\u0001\u0000\u0000"+
		"\u0000\u01e0\u01e1\u0001\u0000\u0000\u0000\u01e1\u01e3\u0001\u0000\u0000"+
		"\u0000\u01e2\u01e0\u0001\u0000\u0000\u0000\u01e3\u01e5\u0005\u0003\u0000"+
		"\u0000\u01e4\u0188\u0001\u0000\u0000\u0000\u01e4\u01b1\u0001\u0000\u0000"+
		"\u0000\u01e4\u01d0\u0001\u0000\u0000\u0000\u01e5\u000b\u0001\u0000\u0000"+
		"\u0000O\u000f\u0015\u001b\"(.38=CKQW\\bjpvz\u0080\u0086\u008c\u0091\u0096"+
		"\u009b\u00a1\u00a9\u00af\u00b5\u00ba\u00c0\u00c8\u00ce\u00d4\u00dc\u00e2"+
		"\u00e8\u00ed\u00f2\u00f7\u00fd\u0105\u010b\u0111\u0116\u011c\u0120\u0126"+
		"\u012c\u0132\u0137\u013c\u0141\u0147\u014f\u0155\u015b\u0160\u0166\u016e"+
		"\u0174\u017a\u017e\u018c\u0192\u0198\u019d\u01a2\u01a7\u01ad\u01b5\u01bb"+
		"\u01c1\u01c6\u01cc\u01d4\u01da\u01e0\u01e4";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}