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
		INDUCTOR_NAME=6, COMPONENT_VALUE=7, NUMERIC_VALUE=8, NUMBERS=9, END=10, 
		PARAMS=11, TEXT=12;
	public static final int
		RULE_main = 0, RULE_resistor = 1, RULE_capacitor = 2, RULE_inductor = 3;
	private static String[] makeRuleNames() {
		return new String[] {
			"main", "resistor", "capacitor", "inductor"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, null, "'.end'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "COMMENT", "WHITESPACE", "NEWLINE", "RESISTOR_NAME", "CAPACITOR_NAME", 
			"INDUCTOR_NAME", "COMPONENT_VALUE", "NUMERIC_VALUE", "NUMBERS", "END", 
			"PARAMS", "TEXT"
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
			setState(11);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==RESISTOR_NAME) {
				{
				{
				setState(8);
				resistor();
				}
				}
				setState(13);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(17);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==CAPACITOR_NAME) {
				{
				{
				setState(14);
				capacitor();
				}
				}
				setState(19);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(23);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==INDUCTOR_NAME) {
				{
				{
				setState(20);
				inductor();
				}
				}
				setState(25);
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
			setState(118);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,18,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				{
				setState(26);
				match(RESISTOR_NAME);
				setState(28); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(27);
					match(WHITESPACE);
					}
					}
					setState(30); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHITESPACE );
				setState(32);
				match(TEXT);
				setState(34); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(33);
					match(WHITESPACE);
					}
					}
					setState(36); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHITESPACE );
				setState(38);
				match(TEXT);
				setState(40); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(39);
					match(WHITESPACE);
					}
					}
					setState(42); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHITESPACE );
				setState(45); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(44);
					match(NUMERIC_VALUE);
					}
					}
					setState(47); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==NUMERIC_VALUE );
				setState(50); 
				_errHandler.sync(this);
				_alt = 1;
				do {
					switch (_alt) {
					case 1:
						{
						{
						setState(49);
						match(WHITESPACE);
						}
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					setState(52); 
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,7,_ctx);
				} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
				setState(57);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==PARAMS) {
					{
					{
					setState(54);
					match(PARAMS);
					}
					}
					setState(59);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(63);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WHITESPACE) {
					{
					{
					setState(60);
					match(WHITESPACE);
					}
					}
					setState(65);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(66);
				match(NEWLINE);
				}
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				{
				setState(67);
				match(RESISTOR_NAME);
				setState(69); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(68);
					match(WHITESPACE);
					}
					}
					setState(71); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHITESPACE );
				setState(73);
				match(TEXT);
				setState(75); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(74);
					match(WHITESPACE);
					}
					}
					setState(77); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHITESPACE );
				setState(79);
				match(TEXT);
				setState(81); 
				_errHandler.sync(this);
				_alt = 1;
				do {
					switch (_alt) {
					case 1:
						{
						{
						setState(80);
						match(WHITESPACE);
						}
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					setState(83); 
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
				} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
				setState(88);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==NUMERIC_VALUE) {
					{
					{
					setState(85);
					match(NUMERIC_VALUE);
					}
					}
					setState(90);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(94);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WHITESPACE) {
					{
					{
					setState(91);
					match(WHITESPACE);
					}
					}
					setState(96);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(97);
				match(NEWLINE);
				}
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				{
				setState(98);
				match(RESISTOR_NAME);
				setState(100); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(99);
					match(WHITESPACE);
					}
					}
					setState(102); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHITESPACE );
				setState(104);
				match(TEXT);
				setState(106); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(105);
					match(WHITESPACE);
					}
					}
					setState(108); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHITESPACE );
				setState(110);
				match(TEXT);
				setState(114);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WHITESPACE) {
					{
					{
					setState(111);
					match(WHITESPACE);
					}
					}
					setState(116);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(117);
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
			setState(212);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,34,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				{
				setState(120);
				match(CAPACITOR_NAME);
				setState(122); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(121);
					match(WHITESPACE);
					}
					}
					setState(124); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHITESPACE );
				setState(126);
				match(TEXT);
				setState(128); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(127);
					match(WHITESPACE);
					}
					}
					setState(130); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHITESPACE );
				setState(132);
				match(TEXT);
				setState(134); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(133);
					match(WHITESPACE);
					}
					}
					setState(136); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHITESPACE );
				setState(139); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(138);
					match(NUMERIC_VALUE);
					}
					}
					setState(141); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==NUMERIC_VALUE );
				setState(144); 
				_errHandler.sync(this);
				_alt = 1;
				do {
					switch (_alt) {
					case 1:
						{
						{
						setState(143);
						match(WHITESPACE);
						}
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					setState(146); 
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,23,_ctx);
				} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
				setState(151);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==PARAMS) {
					{
					{
					setState(148);
					match(PARAMS);
					}
					}
					setState(153);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(157);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WHITESPACE) {
					{
					{
					setState(154);
					match(WHITESPACE);
					}
					}
					setState(159);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(160);
				match(NEWLINE);
				}
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				{
				setState(161);
				match(CAPACITOR_NAME);
				setState(163); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(162);
					match(WHITESPACE);
					}
					}
					setState(165); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHITESPACE );
				setState(167);
				match(TEXT);
				setState(169); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(168);
					match(WHITESPACE);
					}
					}
					setState(171); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHITESPACE );
				setState(173);
				match(TEXT);
				setState(175); 
				_errHandler.sync(this);
				_alt = 1;
				do {
					switch (_alt) {
					case 1:
						{
						{
						setState(174);
						match(WHITESPACE);
						}
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					setState(177); 
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,28,_ctx);
				} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
				setState(182);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==NUMERIC_VALUE) {
					{
					{
					setState(179);
					match(NUMERIC_VALUE);
					}
					}
					setState(184);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(188);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WHITESPACE) {
					{
					{
					setState(185);
					match(WHITESPACE);
					}
					}
					setState(190);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(191);
				match(NEWLINE);
				}
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				{
				setState(192);
				match(CAPACITOR_NAME);
				setState(194); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(193);
					match(WHITESPACE);
					}
					}
					setState(196); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHITESPACE );
				setState(198);
				match(TEXT);
				setState(200); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(199);
					match(WHITESPACE);
					}
					}
					setState(202); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHITESPACE );
				setState(204);
				match(TEXT);
				setState(208);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WHITESPACE) {
					{
					{
					setState(205);
					match(WHITESPACE);
					}
					}
					setState(210);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(211);
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
			setState(306);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,50,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				{
				setState(214);
				match(INDUCTOR_NAME);
				setState(216); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(215);
					match(WHITESPACE);
					}
					}
					setState(218); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHITESPACE );
				setState(220);
				match(TEXT);
				setState(222); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(221);
					match(WHITESPACE);
					}
					}
					setState(224); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHITESPACE );
				setState(226);
				match(TEXT);
				setState(228); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(227);
					match(WHITESPACE);
					}
					}
					setState(230); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHITESPACE );
				setState(233); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(232);
					match(NUMERIC_VALUE);
					}
					}
					setState(235); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==NUMERIC_VALUE );
				setState(238); 
				_errHandler.sync(this);
				_alt = 1;
				do {
					switch (_alt) {
					case 1:
						{
						{
						setState(237);
						match(WHITESPACE);
						}
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					setState(240); 
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,39,_ctx);
				} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
				setState(245);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==PARAMS) {
					{
					{
					setState(242);
					match(PARAMS);
					}
					}
					setState(247);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(251);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WHITESPACE) {
					{
					{
					setState(248);
					match(WHITESPACE);
					}
					}
					setState(253);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(254);
				match(NEWLINE);
				}
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				{
				setState(255);
				match(INDUCTOR_NAME);
				setState(257); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(256);
					match(WHITESPACE);
					}
					}
					setState(259); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHITESPACE );
				setState(261);
				match(TEXT);
				setState(263); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(262);
					match(WHITESPACE);
					}
					}
					setState(265); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHITESPACE );
				setState(267);
				match(TEXT);
				setState(269); 
				_errHandler.sync(this);
				_alt = 1;
				do {
					switch (_alt) {
					case 1:
						{
						{
						setState(268);
						match(WHITESPACE);
						}
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					setState(271); 
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,44,_ctx);
				} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
				setState(276);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==NUMERIC_VALUE) {
					{
					{
					setState(273);
					match(NUMERIC_VALUE);
					}
					}
					setState(278);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(282);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WHITESPACE) {
					{
					{
					setState(279);
					match(WHITESPACE);
					}
					}
					setState(284);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(285);
				match(NEWLINE);
				}
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				{
				setState(286);
				match(INDUCTOR_NAME);
				setState(288); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(287);
					match(WHITESPACE);
					}
					}
					setState(290); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHITESPACE );
				setState(292);
				match(TEXT);
				setState(294); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(293);
					match(WHITESPACE);
					}
					}
					setState(296); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHITESPACE );
				setState(298);
				match(TEXT);
				setState(302);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WHITESPACE) {
					{
					{
					setState(299);
					match(WHITESPACE);
					}
					}
					setState(304);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(305);
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
		"\u0004\u0001\f\u0135\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0002"+
		"\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0001\u0000\u0005\u0000\n\b"+
		"\u0000\n\u0000\f\u0000\r\t\u0000\u0001\u0000\u0005\u0000\u0010\b\u0000"+
		"\n\u0000\f\u0000\u0013\t\u0000\u0001\u0000\u0005\u0000\u0016\b\u0000\n"+
		"\u0000\f\u0000\u0019\t\u0000\u0001\u0001\u0001\u0001\u0004\u0001\u001d"+
		"\b\u0001\u000b\u0001\f\u0001\u001e\u0001\u0001\u0001\u0001\u0004\u0001"+
		"#\b\u0001\u000b\u0001\f\u0001$\u0001\u0001\u0001\u0001\u0004\u0001)\b"+
		"\u0001\u000b\u0001\f\u0001*\u0001\u0001\u0004\u0001.\b\u0001\u000b\u0001"+
		"\f\u0001/\u0001\u0001\u0004\u00013\b\u0001\u000b\u0001\f\u00014\u0001"+
		"\u0001\u0005\u00018\b\u0001\n\u0001\f\u0001;\t\u0001\u0001\u0001\u0005"+
		"\u0001>\b\u0001\n\u0001\f\u0001A\t\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0004\u0001F\b\u0001\u000b\u0001\f\u0001G\u0001\u0001\u0001\u0001"+
		"\u0004\u0001L\b\u0001\u000b\u0001\f\u0001M\u0001\u0001\u0001\u0001\u0004"+
		"\u0001R\b\u0001\u000b\u0001\f\u0001S\u0001\u0001\u0005\u0001W\b\u0001"+
		"\n\u0001\f\u0001Z\t\u0001\u0001\u0001\u0005\u0001]\b\u0001\n\u0001\f\u0001"+
		"`\t\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0004\u0001e\b\u0001\u000b"+
		"\u0001\f\u0001f\u0001\u0001\u0001\u0001\u0004\u0001k\b\u0001\u000b\u0001"+
		"\f\u0001l\u0001\u0001\u0001\u0001\u0005\u0001q\b\u0001\n\u0001\f\u0001"+
		"t\t\u0001\u0001\u0001\u0003\u0001w\b\u0001\u0001\u0002\u0001\u0002\u0004"+
		"\u0002{\b\u0002\u000b\u0002\f\u0002|\u0001\u0002\u0001\u0002\u0004\u0002"+
		"\u0081\b\u0002\u000b\u0002\f\u0002\u0082\u0001\u0002\u0001\u0002\u0004"+
		"\u0002\u0087\b\u0002\u000b\u0002\f\u0002\u0088\u0001\u0002\u0004\u0002"+
		"\u008c\b\u0002\u000b\u0002\f\u0002\u008d\u0001\u0002\u0004\u0002\u0091"+
		"\b\u0002\u000b\u0002\f\u0002\u0092\u0001\u0002\u0005\u0002\u0096\b\u0002"+
		"\n\u0002\f\u0002\u0099\t\u0002\u0001\u0002\u0005\u0002\u009c\b\u0002\n"+
		"\u0002\f\u0002\u009f\t\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0004"+
		"\u0002\u00a4\b\u0002\u000b\u0002\f\u0002\u00a5\u0001\u0002\u0001\u0002"+
		"\u0004\u0002\u00aa\b\u0002\u000b\u0002\f\u0002\u00ab\u0001\u0002\u0001"+
		"\u0002\u0004\u0002\u00b0\b\u0002\u000b\u0002\f\u0002\u00b1\u0001\u0002"+
		"\u0005\u0002\u00b5\b\u0002\n\u0002\f\u0002\u00b8\t\u0002\u0001\u0002\u0005"+
		"\u0002\u00bb\b\u0002\n\u0002\f\u0002\u00be\t\u0002\u0001\u0002\u0001\u0002"+
		"\u0001\u0002\u0004\u0002\u00c3\b\u0002\u000b\u0002\f\u0002\u00c4\u0001"+
		"\u0002\u0001\u0002\u0004\u0002\u00c9\b\u0002\u000b\u0002\f\u0002\u00ca"+
		"\u0001\u0002\u0001\u0002\u0005\u0002\u00cf\b\u0002\n\u0002\f\u0002\u00d2"+
		"\t\u0002\u0001\u0002\u0003\u0002\u00d5\b\u0002\u0001\u0003\u0001\u0003"+
		"\u0004\u0003\u00d9\b\u0003\u000b\u0003\f\u0003\u00da\u0001\u0003\u0001"+
		"\u0003\u0004\u0003\u00df\b\u0003\u000b\u0003\f\u0003\u00e0\u0001\u0003"+
		"\u0001\u0003\u0004\u0003\u00e5\b\u0003\u000b\u0003\f\u0003\u00e6\u0001"+
		"\u0003\u0004\u0003\u00ea\b\u0003\u000b\u0003\f\u0003\u00eb\u0001\u0003"+
		"\u0004\u0003\u00ef\b\u0003\u000b\u0003\f\u0003\u00f0\u0001\u0003\u0005"+
		"\u0003\u00f4\b\u0003\n\u0003\f\u0003\u00f7\t\u0003\u0001\u0003\u0005\u0003"+
		"\u00fa\b\u0003\n\u0003\f\u0003\u00fd\t\u0003\u0001\u0003\u0001\u0003\u0001"+
		"\u0003\u0004\u0003\u0102\b\u0003\u000b\u0003\f\u0003\u0103\u0001\u0003"+
		"\u0001\u0003\u0004\u0003\u0108\b\u0003\u000b\u0003\f\u0003\u0109\u0001"+
		"\u0003\u0001\u0003\u0004\u0003\u010e\b\u0003\u000b\u0003\f\u0003\u010f"+
		"\u0001\u0003\u0005\u0003\u0113\b\u0003\n\u0003\f\u0003\u0116\t\u0003\u0001"+
		"\u0003\u0005\u0003\u0119\b\u0003\n\u0003\f\u0003\u011c\t\u0003\u0001\u0003"+
		"\u0001\u0003\u0001\u0003\u0004\u0003\u0121\b\u0003\u000b\u0003\f\u0003"+
		"\u0122\u0001\u0003\u0001\u0003\u0004\u0003\u0127\b\u0003\u000b\u0003\f"+
		"\u0003\u0128\u0001\u0003\u0001\u0003\u0005\u0003\u012d\b\u0003\n\u0003"+
		"\f\u0003\u0130\t\u0003\u0001\u0003\u0003\u0003\u0133\b\u0003\u0001\u0003"+
		"\u0000\u0000\u0004\u0000\u0002\u0004\u0006\u0000\u0000\u0166\u0000\u000b"+
		"\u0001\u0000\u0000\u0000\u0002v\u0001\u0000\u0000\u0000\u0004\u00d4\u0001"+
		"\u0000\u0000\u0000\u0006\u0132\u0001\u0000\u0000\u0000\b\n\u0003\u0002"+
		"\u0001\u0000\t\b\u0001\u0000\u0000\u0000\n\r\u0001\u0000\u0000\u0000\u000b"+
		"\t\u0001\u0000\u0000\u0000\u000b\f\u0001\u0000\u0000\u0000\f\u0011\u0001"+
		"\u0000\u0000\u0000\r\u000b\u0001\u0000\u0000\u0000\u000e\u0010\u0003\u0004"+
		"\u0002\u0000\u000f\u000e\u0001\u0000\u0000\u0000\u0010\u0013\u0001\u0000"+
		"\u0000\u0000\u0011\u000f\u0001\u0000\u0000\u0000\u0011\u0012\u0001\u0000"+
		"\u0000\u0000\u0012\u0017\u0001\u0000\u0000\u0000\u0013\u0011\u0001\u0000"+
		"\u0000\u0000\u0014\u0016\u0003\u0006\u0003\u0000\u0015\u0014\u0001\u0000"+
		"\u0000\u0000\u0016\u0019\u0001\u0000\u0000\u0000\u0017\u0015\u0001\u0000"+
		"\u0000\u0000\u0017\u0018\u0001\u0000\u0000\u0000\u0018\u0001\u0001\u0000"+
		"\u0000\u0000\u0019\u0017\u0001\u0000\u0000\u0000\u001a\u001c\u0005\u0004"+
		"\u0000\u0000\u001b\u001d\u0005\u0002\u0000\u0000\u001c\u001b\u0001\u0000"+
		"\u0000\u0000\u001d\u001e\u0001\u0000\u0000\u0000\u001e\u001c\u0001\u0000"+
		"\u0000\u0000\u001e\u001f\u0001\u0000\u0000\u0000\u001f \u0001\u0000\u0000"+
		"\u0000 \"\u0005\f\u0000\u0000!#\u0005\u0002\u0000\u0000\"!\u0001\u0000"+
		"\u0000\u0000#$\u0001\u0000\u0000\u0000$\"\u0001\u0000\u0000\u0000$%\u0001"+
		"\u0000\u0000\u0000%&\u0001\u0000\u0000\u0000&(\u0005\f\u0000\u0000\')"+
		"\u0005\u0002\u0000\u0000(\'\u0001\u0000\u0000\u0000)*\u0001\u0000\u0000"+
		"\u0000*(\u0001\u0000\u0000\u0000*+\u0001\u0000\u0000\u0000+-\u0001\u0000"+
		"\u0000\u0000,.\u0005\b\u0000\u0000-,\u0001\u0000\u0000\u0000./\u0001\u0000"+
		"\u0000\u0000/-\u0001\u0000\u0000\u0000/0\u0001\u0000\u0000\u000002\u0001"+
		"\u0000\u0000\u000013\u0005\u0002\u0000\u000021\u0001\u0000\u0000\u0000"+
		"34\u0001\u0000\u0000\u000042\u0001\u0000\u0000\u000045\u0001\u0000\u0000"+
		"\u000059\u0001\u0000\u0000\u000068\u0005\u000b\u0000\u000076\u0001\u0000"+
		"\u0000\u00008;\u0001\u0000\u0000\u000097\u0001\u0000\u0000\u00009:\u0001"+
		"\u0000\u0000\u0000:?\u0001\u0000\u0000\u0000;9\u0001\u0000\u0000\u0000"+
		"<>\u0005\u0002\u0000\u0000=<\u0001\u0000\u0000\u0000>A\u0001\u0000\u0000"+
		"\u0000?=\u0001\u0000\u0000\u0000?@\u0001\u0000\u0000\u0000@B\u0001\u0000"+
		"\u0000\u0000A?\u0001\u0000\u0000\u0000Bw\u0005\u0003\u0000\u0000CE\u0005"+
		"\u0004\u0000\u0000DF\u0005\u0002\u0000\u0000ED\u0001\u0000\u0000\u0000"+
		"FG\u0001\u0000\u0000\u0000GE\u0001\u0000\u0000\u0000GH\u0001\u0000\u0000"+
		"\u0000HI\u0001\u0000\u0000\u0000IK\u0005\f\u0000\u0000JL\u0005\u0002\u0000"+
		"\u0000KJ\u0001\u0000\u0000\u0000LM\u0001\u0000\u0000\u0000MK\u0001\u0000"+
		"\u0000\u0000MN\u0001\u0000\u0000\u0000NO\u0001\u0000\u0000\u0000OQ\u0005"+
		"\f\u0000\u0000PR\u0005\u0002\u0000\u0000QP\u0001\u0000\u0000\u0000RS\u0001"+
		"\u0000\u0000\u0000SQ\u0001\u0000\u0000\u0000ST\u0001\u0000\u0000\u0000"+
		"TX\u0001\u0000\u0000\u0000UW\u0005\b\u0000\u0000VU\u0001\u0000\u0000\u0000"+
		"WZ\u0001\u0000\u0000\u0000XV\u0001\u0000\u0000\u0000XY\u0001\u0000\u0000"+
		"\u0000Y^\u0001\u0000\u0000\u0000ZX\u0001\u0000\u0000\u0000[]\u0005\u0002"+
		"\u0000\u0000\\[\u0001\u0000\u0000\u0000]`\u0001\u0000\u0000\u0000^\\\u0001"+
		"\u0000\u0000\u0000^_\u0001\u0000\u0000\u0000_a\u0001\u0000\u0000\u0000"+
		"`^\u0001\u0000\u0000\u0000aw\u0005\u0003\u0000\u0000bd\u0005\u0004\u0000"+
		"\u0000ce\u0005\u0002\u0000\u0000dc\u0001\u0000\u0000\u0000ef\u0001\u0000"+
		"\u0000\u0000fd\u0001\u0000\u0000\u0000fg\u0001\u0000\u0000\u0000gh\u0001"+
		"\u0000\u0000\u0000hj\u0005\f\u0000\u0000ik\u0005\u0002\u0000\u0000ji\u0001"+
		"\u0000\u0000\u0000kl\u0001\u0000\u0000\u0000lj\u0001\u0000\u0000\u0000"+
		"lm\u0001\u0000\u0000\u0000mn\u0001\u0000\u0000\u0000nr\u0005\f\u0000\u0000"+
		"oq\u0005\u0002\u0000\u0000po\u0001\u0000\u0000\u0000qt\u0001\u0000\u0000"+
		"\u0000rp\u0001\u0000\u0000\u0000rs\u0001\u0000\u0000\u0000su\u0001\u0000"+
		"\u0000\u0000tr\u0001\u0000\u0000\u0000uw\u0005\u0003\u0000\u0000v\u001a"+
		"\u0001\u0000\u0000\u0000vC\u0001\u0000\u0000\u0000vb\u0001\u0000\u0000"+
		"\u0000w\u0003\u0001\u0000\u0000\u0000xz\u0005\u0005\u0000\u0000y{\u0005"+
		"\u0002\u0000\u0000zy\u0001\u0000\u0000\u0000{|\u0001\u0000\u0000\u0000"+
		"|z\u0001\u0000\u0000\u0000|}\u0001\u0000\u0000\u0000}~\u0001\u0000\u0000"+
		"\u0000~\u0080\u0005\f\u0000\u0000\u007f\u0081\u0005\u0002\u0000\u0000"+
		"\u0080\u007f\u0001\u0000\u0000\u0000\u0081\u0082\u0001\u0000\u0000\u0000"+
		"\u0082\u0080\u0001\u0000\u0000\u0000\u0082\u0083\u0001\u0000\u0000\u0000"+
		"\u0083\u0084\u0001\u0000\u0000\u0000\u0084\u0086\u0005\f\u0000\u0000\u0085"+
		"\u0087\u0005\u0002\u0000\u0000\u0086\u0085\u0001\u0000\u0000\u0000\u0087"+
		"\u0088\u0001\u0000\u0000\u0000\u0088\u0086\u0001\u0000\u0000\u0000\u0088"+
		"\u0089\u0001\u0000\u0000\u0000\u0089\u008b\u0001\u0000\u0000\u0000\u008a"+
		"\u008c\u0005\b\u0000\u0000\u008b\u008a\u0001\u0000\u0000\u0000\u008c\u008d"+
		"\u0001\u0000\u0000\u0000\u008d\u008b\u0001\u0000\u0000\u0000\u008d\u008e"+
		"\u0001\u0000\u0000\u0000\u008e\u0090\u0001\u0000\u0000\u0000\u008f\u0091"+
		"\u0005\u0002\u0000\u0000\u0090\u008f\u0001\u0000\u0000\u0000\u0091\u0092"+
		"\u0001\u0000\u0000\u0000\u0092\u0090\u0001\u0000\u0000\u0000\u0092\u0093"+
		"\u0001\u0000\u0000\u0000\u0093\u0097\u0001\u0000\u0000\u0000\u0094\u0096"+
		"\u0005\u000b\u0000\u0000\u0095\u0094\u0001\u0000\u0000\u0000\u0096\u0099"+
		"\u0001\u0000\u0000\u0000\u0097\u0095\u0001\u0000\u0000\u0000\u0097\u0098"+
		"\u0001\u0000\u0000\u0000\u0098\u009d\u0001\u0000\u0000\u0000\u0099\u0097"+
		"\u0001\u0000\u0000\u0000\u009a\u009c\u0005\u0002\u0000\u0000\u009b\u009a"+
		"\u0001\u0000\u0000\u0000\u009c\u009f\u0001\u0000\u0000\u0000\u009d\u009b"+
		"\u0001\u0000\u0000\u0000\u009d\u009e\u0001\u0000\u0000\u0000\u009e\u00a0"+
		"\u0001\u0000\u0000\u0000\u009f\u009d\u0001\u0000\u0000\u0000\u00a0\u00d5"+
		"\u0005\u0003\u0000\u0000\u00a1\u00a3\u0005\u0005\u0000\u0000\u00a2\u00a4"+
		"\u0005\u0002\u0000\u0000\u00a3\u00a2\u0001\u0000\u0000\u0000\u00a4\u00a5"+
		"\u0001\u0000\u0000\u0000\u00a5\u00a3\u0001\u0000\u0000\u0000\u00a5\u00a6"+
		"\u0001\u0000\u0000\u0000\u00a6\u00a7\u0001\u0000\u0000\u0000\u00a7\u00a9"+
		"\u0005\f\u0000\u0000\u00a8\u00aa\u0005\u0002\u0000\u0000\u00a9\u00a8\u0001"+
		"\u0000\u0000\u0000\u00aa\u00ab\u0001\u0000\u0000\u0000\u00ab\u00a9\u0001"+
		"\u0000\u0000\u0000\u00ab\u00ac\u0001\u0000\u0000\u0000\u00ac\u00ad\u0001"+
		"\u0000\u0000\u0000\u00ad\u00af\u0005\f\u0000\u0000\u00ae\u00b0\u0005\u0002"+
		"\u0000\u0000\u00af\u00ae\u0001\u0000\u0000\u0000\u00b0\u00b1\u0001\u0000"+
		"\u0000\u0000\u00b1\u00af\u0001\u0000\u0000\u0000\u00b1\u00b2\u0001\u0000"+
		"\u0000\u0000\u00b2\u00b6\u0001\u0000\u0000\u0000\u00b3\u00b5\u0005\b\u0000"+
		"\u0000\u00b4\u00b3\u0001\u0000\u0000\u0000\u00b5\u00b8\u0001\u0000\u0000"+
		"\u0000\u00b6\u00b4\u0001\u0000\u0000\u0000\u00b6\u00b7\u0001\u0000\u0000"+
		"\u0000\u00b7\u00bc\u0001\u0000\u0000\u0000\u00b8\u00b6\u0001\u0000\u0000"+
		"\u0000\u00b9\u00bb\u0005\u0002\u0000\u0000\u00ba\u00b9\u0001\u0000\u0000"+
		"\u0000\u00bb\u00be\u0001\u0000\u0000\u0000\u00bc\u00ba\u0001\u0000\u0000"+
		"\u0000\u00bc\u00bd\u0001\u0000\u0000\u0000\u00bd\u00bf\u0001\u0000\u0000"+
		"\u0000\u00be\u00bc\u0001\u0000\u0000\u0000\u00bf\u00d5\u0005\u0003\u0000"+
		"\u0000\u00c0\u00c2\u0005\u0005\u0000\u0000\u00c1\u00c3\u0005\u0002\u0000"+
		"\u0000\u00c2\u00c1\u0001\u0000\u0000\u0000\u00c3\u00c4\u0001\u0000\u0000"+
		"\u0000\u00c4\u00c2\u0001\u0000\u0000\u0000\u00c4\u00c5\u0001\u0000\u0000"+
		"\u0000\u00c5\u00c6\u0001\u0000\u0000\u0000\u00c6\u00c8\u0005\f\u0000\u0000"+
		"\u00c7\u00c9\u0005\u0002\u0000\u0000\u00c8\u00c7\u0001\u0000\u0000\u0000"+
		"\u00c9\u00ca\u0001\u0000\u0000\u0000\u00ca\u00c8\u0001\u0000\u0000\u0000"+
		"\u00ca\u00cb\u0001\u0000\u0000\u0000\u00cb\u00cc\u0001\u0000\u0000\u0000"+
		"\u00cc\u00d0\u0005\f\u0000\u0000\u00cd\u00cf\u0005\u0002\u0000\u0000\u00ce"+
		"\u00cd\u0001\u0000\u0000\u0000\u00cf\u00d2\u0001\u0000\u0000\u0000\u00d0"+
		"\u00ce\u0001\u0000\u0000\u0000\u00d0\u00d1\u0001\u0000\u0000\u0000\u00d1"+
		"\u00d3\u0001\u0000\u0000\u0000\u00d2\u00d0\u0001\u0000\u0000\u0000\u00d3"+
		"\u00d5\u0005\u0003\u0000\u0000\u00d4x\u0001\u0000\u0000\u0000\u00d4\u00a1"+
		"\u0001\u0000\u0000\u0000\u00d4\u00c0\u0001\u0000\u0000\u0000\u00d5\u0005"+
		"\u0001\u0000\u0000\u0000\u00d6\u00d8\u0005\u0006\u0000\u0000\u00d7\u00d9"+
		"\u0005\u0002\u0000\u0000\u00d8\u00d7\u0001\u0000\u0000\u0000\u00d9\u00da"+
		"\u0001\u0000\u0000\u0000\u00da\u00d8\u0001\u0000\u0000\u0000\u00da\u00db"+
		"\u0001\u0000\u0000\u0000\u00db\u00dc\u0001\u0000\u0000\u0000\u00dc\u00de"+
		"\u0005\f\u0000\u0000\u00dd\u00df\u0005\u0002\u0000\u0000\u00de\u00dd\u0001"+
		"\u0000\u0000\u0000\u00df\u00e0\u0001\u0000\u0000\u0000\u00e0\u00de\u0001"+
		"\u0000\u0000\u0000\u00e0\u00e1\u0001\u0000\u0000\u0000\u00e1\u00e2\u0001"+
		"\u0000\u0000\u0000\u00e2\u00e4\u0005\f\u0000\u0000\u00e3\u00e5\u0005\u0002"+
		"\u0000\u0000\u00e4\u00e3\u0001\u0000\u0000\u0000\u00e5\u00e6\u0001\u0000"+
		"\u0000\u0000\u00e6\u00e4\u0001\u0000\u0000\u0000\u00e6\u00e7\u0001\u0000"+
		"\u0000\u0000\u00e7\u00e9\u0001\u0000\u0000\u0000\u00e8\u00ea\u0005\b\u0000"+
		"\u0000\u00e9\u00e8\u0001\u0000\u0000\u0000\u00ea\u00eb\u0001\u0000\u0000"+
		"\u0000\u00eb\u00e9\u0001\u0000\u0000\u0000\u00eb\u00ec\u0001\u0000\u0000"+
		"\u0000\u00ec\u00ee\u0001\u0000\u0000\u0000\u00ed\u00ef\u0005\u0002\u0000"+
		"\u0000\u00ee\u00ed\u0001\u0000\u0000\u0000\u00ef\u00f0\u0001\u0000\u0000"+
		"\u0000\u00f0\u00ee\u0001\u0000\u0000\u0000\u00f0\u00f1\u0001\u0000\u0000"+
		"\u0000\u00f1\u00f5\u0001\u0000\u0000\u0000\u00f2\u00f4\u0005\u000b\u0000"+
		"\u0000\u00f3\u00f2\u0001\u0000\u0000\u0000\u00f4\u00f7\u0001\u0000\u0000"+
		"\u0000\u00f5\u00f3\u0001\u0000\u0000\u0000\u00f5\u00f6\u0001\u0000\u0000"+
		"\u0000\u00f6\u00fb\u0001\u0000\u0000\u0000\u00f7\u00f5\u0001\u0000\u0000"+
		"\u0000\u00f8\u00fa\u0005\u0002\u0000\u0000\u00f9\u00f8\u0001\u0000\u0000"+
		"\u0000\u00fa\u00fd\u0001\u0000\u0000\u0000\u00fb\u00f9\u0001\u0000\u0000"+
		"\u0000\u00fb\u00fc\u0001\u0000\u0000\u0000\u00fc\u00fe\u0001\u0000\u0000"+
		"\u0000\u00fd\u00fb\u0001\u0000\u0000\u0000\u00fe\u0133\u0005\u0003\u0000"+
		"\u0000\u00ff\u0101\u0005\u0006\u0000\u0000\u0100\u0102\u0005\u0002\u0000"+
		"\u0000\u0101\u0100\u0001\u0000\u0000\u0000\u0102\u0103\u0001\u0000\u0000"+
		"\u0000\u0103\u0101\u0001\u0000\u0000\u0000\u0103\u0104\u0001\u0000\u0000"+
		"\u0000\u0104\u0105\u0001\u0000\u0000\u0000\u0105\u0107\u0005\f\u0000\u0000"+
		"\u0106\u0108\u0005\u0002\u0000\u0000\u0107\u0106\u0001\u0000\u0000\u0000"+
		"\u0108\u0109\u0001\u0000\u0000\u0000\u0109\u0107\u0001\u0000\u0000\u0000"+
		"\u0109\u010a\u0001\u0000\u0000\u0000\u010a\u010b\u0001\u0000\u0000\u0000"+
		"\u010b\u010d\u0005\f\u0000\u0000\u010c\u010e\u0005\u0002\u0000\u0000\u010d"+
		"\u010c\u0001\u0000\u0000\u0000\u010e\u010f\u0001\u0000\u0000\u0000\u010f"+
		"\u010d\u0001\u0000\u0000\u0000\u010f\u0110\u0001\u0000\u0000\u0000\u0110"+
		"\u0114\u0001\u0000\u0000\u0000\u0111\u0113\u0005\b\u0000\u0000\u0112\u0111"+
		"\u0001\u0000\u0000\u0000\u0113\u0116\u0001\u0000\u0000\u0000\u0114\u0112"+
		"\u0001\u0000\u0000\u0000\u0114\u0115\u0001\u0000\u0000\u0000\u0115\u011a"+
		"\u0001\u0000\u0000\u0000\u0116\u0114\u0001\u0000\u0000\u0000\u0117\u0119"+
		"\u0005\u0002\u0000\u0000\u0118\u0117\u0001\u0000\u0000\u0000\u0119\u011c"+
		"\u0001\u0000\u0000\u0000\u011a\u0118\u0001\u0000\u0000\u0000\u011a\u011b"+
		"\u0001\u0000\u0000\u0000\u011b\u011d\u0001\u0000\u0000\u0000\u011c\u011a"+
		"\u0001\u0000\u0000\u0000\u011d\u0133\u0005\u0003\u0000\u0000\u011e\u0120"+
		"\u0005\u0006\u0000\u0000\u011f\u0121\u0005\u0002\u0000\u0000\u0120\u011f"+
		"\u0001\u0000\u0000\u0000\u0121\u0122\u0001\u0000\u0000\u0000\u0122\u0120"+
		"\u0001\u0000\u0000\u0000\u0122\u0123\u0001\u0000\u0000\u0000\u0123\u0124"+
		"\u0001\u0000\u0000\u0000\u0124\u0126\u0005\f\u0000\u0000\u0125\u0127\u0005"+
		"\u0002\u0000\u0000\u0126\u0125\u0001\u0000\u0000\u0000\u0127\u0128\u0001"+
		"\u0000\u0000\u0000\u0128\u0126\u0001\u0000\u0000\u0000\u0128\u0129\u0001"+
		"\u0000\u0000\u0000\u0129\u012a\u0001\u0000\u0000\u0000\u012a\u012e\u0005"+
		"\f\u0000\u0000\u012b\u012d\u0005\u0002\u0000\u0000\u012c\u012b\u0001\u0000"+
		"\u0000\u0000\u012d\u0130\u0001\u0000\u0000\u0000\u012e\u012c\u0001\u0000"+
		"\u0000\u0000\u012e\u012f\u0001\u0000\u0000\u0000\u012f\u0131\u0001\u0000"+
		"\u0000\u0000\u0130\u012e\u0001\u0000\u0000\u0000\u0131\u0133\u0005\u0003"+
		"\u0000\u0000\u0132\u00d6\u0001\u0000\u0000\u0000\u0132\u00ff\u0001\u0000"+
		"\u0000\u0000\u0132\u011e\u0001\u0000\u0000\u0000\u0133\u0007\u0001\u0000"+
		"\u0000\u00003\u000b\u0011\u0017\u001e$*/49?GMSX^flrv|\u0082\u0088\u008d"+
		"\u0092\u0097\u009d\u00a5\u00ab\u00b1\u00b6\u00bc\u00c4\u00ca\u00d0\u00d4"+
		"\u00da\u00e0\u00e6\u00eb\u00f0\u00f5\u00fb\u0103\u0109\u010f\u0114\u011a"+
		"\u0122\u0128\u012e\u0132";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}