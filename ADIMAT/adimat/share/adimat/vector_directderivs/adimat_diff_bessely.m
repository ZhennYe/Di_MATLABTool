function varargout = adimat_diff_bessely(varargin)

      if isempty(varargin{1}) || isempty(varargin{3})
        varargout{2} = bessely(varargin{1}, varargin{3});
        varargout{1} = d_zeros(varargout{2});
      else 
        [varargout{1} varargout{2}] = adimat_fdiff_vunary_sexp(varargin{2}, varargin{3}, @(x) dpartial_bessely(varargin{1}, x, varargin{4:end}));
      end
      varargout{4} = 0; % backwards compatibility
      
end
% automatically generated from $Id: derivatives-vdd.xml 3983 2013-12-21 11:20:23Z willkomm $
